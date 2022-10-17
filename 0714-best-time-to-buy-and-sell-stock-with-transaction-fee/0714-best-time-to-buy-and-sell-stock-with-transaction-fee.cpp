class Solution {
public:
    int dp[50001][2];
    
    int findans(vector<int>&v,int fee,int n,int buy )
    {
        if(n<0)
            return 0;
        
        if(dp[n][buy]!=-1)
            return dp[n][buy];
        
        if(buy)
        {
            return dp[n][buy]=max(-v[n]+findans(v,fee,n-1,0),findans(v,fee,n-1,buy));
        }
        else
            return dp[n][buy]=max(v[n]-fee+findans(v,fee,n-1,1),findans(v,fee,n-1,buy));
    }
        int maxProfit(vector<int>& prices, int fee) {
        memset(dp,-1,sizeof(dp));
        reverse(prices.begin(),prices.end());
        return findans(prices,fee,prices.size()-1,1);
    }
};