class Solution {
public:
    int dp[13][10001];
    int findans(vector<int>&c,int sum,int n)
    { 
        if(sum==0)
            return 0;
        if(n==0)
            return INT_MAX-1;
        
        if(dp[n][sum]!=-1)
            return dp[n][sum];
        
        if(c[n-1]<=sum)
            return dp[n][sum]=min(1+findans(c,sum-c[n-1],n),findans(c,sum,n-1));
        else
            return dp[n][sum]=findans(c,sum,n-1);
            
    }
    int coinChange(vector<int>& coins, int amount) {
        sort(coins.begin(),coins.end());
        if(amount==0)
            return 0;
        memset(dp,-1,sizeof(dp));
        findans(coins,amount,coins.size());
        int n=coins.size();
        if(dp[n][amount]==INT_MAX-1)
            return -1;
        else
            return dp[n][amount];
    }
};