class Solution {
public:
    int dp[10001][101];
    
    int findans(string &s,string &t,int n,int m)
    {
        if(m<0)
            return 1;
        if(n<0)
            return 0;
        
        if(dp[n][m]!=-1)
            return dp[n][m];
        
        if(s[n]==t[m])
            return dp[n][m]=findans(s,t,n-1,m-1) ;
        else
        {
            return dp[n][m]=findans(s,t,n-1,m);
        }
    }
    bool isSubsequence(string t, string s) {
        
        memset(dp,-1,sizeof(dp));
        return findans(s,t,s.size()-1,t.size()-1);
    }
};