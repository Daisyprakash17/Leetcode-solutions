class Solution {
public:
      int findans(vector<int>&v,vector<int>&dp,int n,int last )
    {
         if(n<=last)
            return 0;
        if(dp[n-1]!=-1)
            return dp[n-1];
        
        return dp[n-1]=max(v[n-1]+findans(v,dp,n-2,last),findans(v,dp,n-1,last));
    }
    int rob(vector<int>& nums) {
        
         int n=nums.size();
        if(n==1)
            return nums[0];
        vector<int>dp(n,-1),dpp(n,-1);
        
        return max(findans(nums,dp,n,1),findans(nums,dpp,n-1,0));
    }
};