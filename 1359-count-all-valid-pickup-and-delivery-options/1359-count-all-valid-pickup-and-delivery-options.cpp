class Solution {
public:
    int mod=1e9+7;
    long long  findans(long long  n)
    { 
        if(n==1)
            return n;
        return ((n*(2*n-1)%mod)*(findans(n-1)%mod) )%mod;
    }
    int dp[501];
    int countOrders(int n) {   
        return findans(n);
    }
};