class Solution {
public:
    int dp[1000][1000];
    int mod=1e9+7;
    int findans(long long  n,int k)
    {
        if(n==k)
            return 1;
        if(n==0 || k==0)
            return 0;
        if(dp[n][k]!=-1)
            return dp[n][k];
        int ans=0;
        ans=findans(n-1,k-1)%mod;
        ans=(ans+(n-1)*findans(n-1,k)%mod )%mod;
        
        return dp[n][k]=ans;
    }
    int rearrangeSticks(int n, int k) {
        memset(dp,-1,sizeof(dp));
        return findans(n,k);
    }
};