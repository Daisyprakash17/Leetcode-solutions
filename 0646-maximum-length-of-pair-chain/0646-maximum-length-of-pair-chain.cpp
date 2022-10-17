class Solution {
public:
    int dp[1001][1001];
    int findans(vector<vector<int>>&v,int n,int pre)
    {
        if(n<0)
            return 0;
        if(pre!=-1 && dp[n][pre]!=-1)
            return dp[n][pre];
            int res;
        if(pre==-1 || v[n][1]<v[pre][0])
        {
           res =max(findans(v,n-1,pre),1+findans(v,n-1,n));
        }
        else
            res= dp[n][pre]=findans(v,n-1,pre);
        if(pre==-1)
            return res;
        else 
            return dp[n][pre]=res;
    }
    int findLongestChain(vector<vector<int>>& v) {
        sort(v.begin(),v.end());
        memset(dp,-1,sizeof(dp));
        
        return findans(v,v.size()-1,-1);
    }
};