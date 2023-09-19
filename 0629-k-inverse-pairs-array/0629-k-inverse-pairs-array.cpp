class Solution {
public:
    int dp[1001][1001];
    int findans(int n,int k)
    {
        if(k==0)
            return 1;
        if(n==0)
            return 0;
        if(dp[n][k]!=-1)
            return dp[n][k];
        
        int ans=0;
        int mod=1e9+7;
        for(int i=1;i<=n;i++)
        {
            if((n-i)<=k)
            ans=(ans+findans(n-1,k-(n-i)))%mod;
        }
        return dp[n][k]=ans;
    }
    int kInversePairs(int n, int k) {
        memset(dp,-1,sizeof(dp));
        return findans(n,k);
    }
};