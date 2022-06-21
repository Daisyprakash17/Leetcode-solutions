class Solution {
public:
    
    int findans(vector<int>&v,vector<int>&dp,int n)
    {
         if(n<=0)
            return 0;
        if(dp[n-1]!=-1)
            return dp[n-1];
        
        return dp[n-1]=max(v[n-1]+findans(v,dp,n-2),findans(v,dp,n-1));
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        
        vector<int>dp(n,-1);
        
        return findans(nums,dp,n);
        
    }
};