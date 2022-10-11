class Solution {
public:
    int dp[101];
    int findans(vector<int>&nums,int i,int last)
    {
        if(i<=last)
            return 0;
        if(dp[i]!=-1)
            return  dp[i]; 
        return dp[i]=max(nums[i]+findans(nums,i-2,last),findans(nums,i-1,last));
    }
    int rob(vector<int>& nums) {
        if(nums.size()==1)
            return nums[0];
        memset(dp,-1,sizeof(dp));
        int val=findans(nums,nums.size()-1,0);
        memset(dp,-1,sizeof(dp));
        val=max(val,findans(nums,nums.size()-2,-1));
        return val;
    }
};