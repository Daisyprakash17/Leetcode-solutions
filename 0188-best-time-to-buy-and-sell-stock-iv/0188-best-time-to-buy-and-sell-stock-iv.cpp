class Solution {
public:
    int dp[1001][2][101];
    // buy is 1 we have to bug the stock 
    // if buy is 0 then we have to sell the stock
    int maxtransactions;
    int findans(vector<int>&v,int n,int buy,int k)
    {
        if(n==0 || k>=maxtransactions)
            return 0;
        
        int val=0;
        if(dp[n][buy][k]!=-1)
            return dp[n][buy][k];
        if(buy)
        {
            // here i am buying
             val=-v[n-1]+findans(v,n-1,0,k);
            val=max(val,findans(v,n-1,1,k));
        }
        else 
        {
           
                
                 val=v[n-1]+findans(v,n-1,1,k+1);
                val=max(val,findans(v,n-1,0,k));
            
        }
        return dp[n][buy][k]=val;
    }
    int maxProfit(int k, vector<int>& v) {
        maxtransactions=k;
        memset(dp,-1,sizeof(dp));
        reverse(v.begin(),v.end());
        return findans(v,v.size(),1,0);
    }
};