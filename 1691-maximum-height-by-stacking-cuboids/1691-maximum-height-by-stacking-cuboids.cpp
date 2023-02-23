 
class Solution { 
public:
    int dp[101];
    int findans(vector<vector<int>>&v,int i)
    {
        if(i>=v.size())
            return 0;
        if(dp[i]!=-1)
            return dp[i];
        int ans=0;
        for(int j=i+1;j<v.size();j++)
            if(v[j][1]>=v[i][1] && v[j][2]>=v[i][2])
                ans=max(ans,v[j][2]+findans(v,j));
        return dp[i]=ans;
    }
    int maxHeight(vector<vector<int>>& v) {
        memset(dp,-1,sizeof(dp));
        for(int i=0;i<v.size();i++)
            sort(v[i].begin(),v[i].end()); 
        sort(v.begin(),v.end()); 
       
        int ans=0;
        for(int i=0;i<v.size();i++)
        ans=max(ans,v[i][2]+findans(v,i));
        return ans;
    }
};