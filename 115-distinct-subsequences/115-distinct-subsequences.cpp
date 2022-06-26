class Solution {
public:
        int dp[1001][1001];  
    int findans(string &a,string &b,int n,int m)
    {
        if( n==0 && m>0)
            return  0;
        if(m==0)
            return 1;
        if(dp[n][m]!=-1)
            return dp[n][m];
        
        if(a[n-1]==b[m-1])
            return dp[n][m]=findans(a,b,n-1,m)+findans(a,b,n-1,m-1);
        else
            return dp[n][m]=findans(a,b,n-1,m);
    }
    int numDistinct(string s, string t) {
        
        int n=s.size();
        int m=t.size();
        memset(dp,-1,sizeof(dp));
        return findans(s,t,n,m);
    }
};