class Solution {
public:
    
    int dp[100002];
    int mod=1e9+7;
    int findans(int i,int zero,int one)
    {
        if(i==0)
            return 1;
        if(i<0)
            return 0;
        if(dp[i]!=-1)
            return dp[i];
        int val=0;
        val=(findans(i-zero,zero,one)+findans(i-one,zero,one))%mod;
        return dp[i]=val;
    }
    int countGoodStrings(int low, int high, int zero, int one) {
        memset(dp,-1,sizeof(dp));
        int res=0;
        for(int i=low;i<=high;i++)
        res=(res+findans(i,zero,one))%mod;
    
         return res;    
    }
};