class Solution {
public:
    
    int dp[101];
    int findans(int i,int n,vector<int>&v)
    {
            if(i>=n)
                return 0 ;
        if(dp[i]!=-1)
            return dp[i];
        
        int ans=0;
        ans=max(v[i]+findans(i+2,n,v),findans(i+1,n,v));
        return dp[i]=ans;
    }
    int rob(vector<int>& nums) {
        if(nums.size()==1)
            return nums[0];
        else if(nums.size()==2)
            return max(nums[0],nums[1]); 
        
        
        dp[0]=0;
        dp[1]=nums[0];
        
        for(int i=1;i<nums.size();i++)
        {
            dp[i+1]=max(nums[i]+dp[i-1],dp[i]);
            
        }
        return dp[nums.size()];
        
    }
};