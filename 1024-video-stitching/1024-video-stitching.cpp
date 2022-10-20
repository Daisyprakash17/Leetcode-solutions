class Solution {
public:
    int dp[102][102];
    int findans(vector<vector<int>>&v,int cur,int pre,int time)
    {
        if(v[pre][1]>=time)
            return 0; 
        if(cur>=v.size())
            return -1; // and is noe possible
        
        
        if(v[pre][1]<v[cur][0])
            return -1; // in this case also ans is not possible
        
        if(dp[cur][pre]!=-1)
            return dp[cur][pre];
        
        int val=INT_MAX;
        if(v[pre][1]<=v[cur][1])
        {
            int first=findans(v,cur+1,cur,time);
            int second=findans(v,cur+1,pre,time);
            if(first>=0)
                val=min(val,1+first);
            if(second>=0)
                val=min(val,second);
        }
        else
        {
            val=findans(v,cur+1,pre,time);
        }
        if(val==INT_MAX)
            val=-1;
        return dp[cur][pre]=val;
    }
    int videoStitching(vector<vector<int>>& v, int time) {
       
        v.push_back({0,0}); 
        sort(v.begin(),v.end());
        
        memset(dp,-1,sizeof(dp));
        return findans(v,1,0,time);
         
        }
};