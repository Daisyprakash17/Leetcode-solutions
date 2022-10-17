class Solution {
public:
    int dp[20001][21];
        
    int findans(vector<int>&v,int sum,int n) 
    {
        if(sum==0 && n<0)
            return true;
        if(n<0 && sum!=0)
            return false;
        
        if(dp[sum][n]!=-1)
            return dp[sum][n];
        
        if(v[n]<=sum)
        {
           return  dp[sum][n]=findans(v,sum-v[n],n-1)+findans(v,sum,n-1);
            
        }
        
        else
            return dp[sum][n]=findans(v,sum,n-1);
    }
        int findTargetSumWays(vector<int>& nums, int t) {
        t=abs(t);
        int sum=0;
        for(auto i:nums)
            sum+=i;
        if((sum+t)%2==1 || sum<t)
            return 0;
        
        sum=(sum+t)/2;
        
        
        memset(dp,-1,sizeof(dp));
            return findans(nums,sum,nums.size()-1);
    
        
    }
};