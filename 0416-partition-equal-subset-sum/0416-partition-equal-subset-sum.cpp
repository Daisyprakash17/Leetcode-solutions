class Solution {
public:
     int dp[10001][201];
    int findans(int i,int n,int sum,vector<int>&v)
    {
        if(i>=n)
        {
            if(sum==0)
                return true;
            else
                return false;
        }
        
        if(dp[sum][i]!=-1)
            return dp[sum][i];
        
        int ans=0;
        if(sum>=v[i])
            ans=ans||findans(i+1,n,sum-v[i],v);
        ans=ans||findans(i+1,n,sum,v);
        return dp[sum][i]=ans;
            
            
        }
    bool canPartition(vector<int>& nums) {
        int sum=0;
        memset(dp,-1,sizeof(dp));
        for(auto i:nums)
            sum+=i;
        
        if(sum%2==1)
            return false;
        return findans(0,nums.size(),sum/2,nums);
    }
};