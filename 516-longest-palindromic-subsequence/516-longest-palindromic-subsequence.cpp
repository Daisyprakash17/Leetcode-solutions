class Solution {
public:
      int dp[1001][1001];
    int findans(string &a,string &b,int n,int m)
    {
        
        if(n==0 || m==0)
        {
            return 0;
        }
        if(dp[n][m]!=-1)
            return dp[n][m];
        if(a[n-1]==b[m-1])
            return dp[n][m]=1+findans(a,b,n-1,m-1);
        else
            return dp[n][m]=max(findans(a,b,n,m-1),findans(a,b,n-1,m));
    }
    int longestPalindromeSubseq(string a) {
        
       memset(dp,-1,sizeof(dp));
        string b=a;
        reverse(b.begin(),b.end());
        return findans(a,b,a.size(),a.size());
    }
};