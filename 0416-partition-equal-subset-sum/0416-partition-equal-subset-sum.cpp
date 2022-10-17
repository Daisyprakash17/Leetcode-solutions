class Solution {
public:
    int dp[10001][201];
    
    int findans(vector<int>&v,int sum,int n)
    {
        if(sum==0)
            return true;
        if(n<0)
            return false;
        
        if(dp[sum][n]!=-1)
            return dp[sum][n];
        
        if(v[n]<=sum)
        {
           return  dp[sum][n]=findans(v,sum-v[n],n-1)|findans(v,sum,n-1);
            
        }
        
        else
            return dp[sum][n]=findans(v,sum,n-1);
    }
    
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(auto i:nums)
            sum+=i;
        
        if(sum%2==1)
            return false;
        
        sum=sum/2;
        memset(dp,-1,sizeof(dp));
        return findans(nums,sum,nums.size()-1);
    }
};