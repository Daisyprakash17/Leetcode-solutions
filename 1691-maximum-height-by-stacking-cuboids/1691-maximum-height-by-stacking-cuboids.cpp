 
class Solution { 
public:
    int dp[101][101];
    int findans(vector<vector<int>>&v,int i,int pre)
    {
        if(i>=v.size())
            return 0;
        if(dp[i][pre]!=-1)
            return dp[i][pre];
        int ans=0;
        if(v[pre][1]<=v[i][1] && v[pre][2]<=v[i][2])
            ans=max(ans,v[i][2]+findans(v,i+1,i));
        ans=max(ans,findans(v,i+1,pre));
        return dp[i][pre]=ans;
    }
    int maxHeight(vector<vector<int>>& v) {
        memset(dp,-1,sizeof(dp));
        for(int i=0;i<v.size();i++)
            sort(v[i].begin(),v[i].end()); 
        sort(v.begin(),v.end()); 
       
        int ans=0;
        for(int i=0;i<v.size();i++)
        ans=max(ans,v[i][2]+findans(v,i+1,i));
        return ans;
    }
};