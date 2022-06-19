class Solution {
public:
    int dp[201][10001];
     int findans(vector<int>&arr,int sum,int n)
    {
        
        if(sum==0)// if sum is zero empty set will make the sum
            return 1;
        if(n==0)// if n is zero that means that we cannot make the subset with the given sum
            return 0;
        
        
        if(dp[n][sum]!=-1)
            return dp[n][sum];
        
        if(arr[n-1]<=sum)
            return dp[n][sum]=(findans(arr,sum-arr[n-1],n-1) || findans(arr,sum,n-1));
        else
            return dp[n][sum]=findans(arr,sum,n-1);
    }
    bool canPartition(vector<int>& nums) {
    
        int sum=0;
        for(auto i:nums)
        sum+=i;
        if(sum%2==1)
            return 0;
            memset(dp,-1,sizeof(dp));
        findans(nums,sum/2,nums.size());
        return dp[nums.size()][sum/2];
    }
};