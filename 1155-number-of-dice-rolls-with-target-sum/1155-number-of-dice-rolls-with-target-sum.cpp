class Solution {
public:
    int dp[1001][31];
    int mod=1000000007;
    int findans(int sum,int n,int k)
    {
        if(n==0 && sum==0)
            return 1;
        if(sum==0  || n==0)
            return 0;
        if(dp[sum][n]!=-1)
            return dp[sum][n];
        
        int val=0;
        for(int i=1;i<=k;i++)
        {
            if(i<=sum)
                val=(val+findans(sum-i,n-1,k))%mod;
        }
        return dp[sum][n]=val;
    }
    int numRollsToTarget(int n, int k, int target) {
        
        memset(dp,-1,sizeof(dp));
        return findans(target,n,k);
    }
};