class Solution {
public:
    
    int dp[100];
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
        memset(dp,-1,sizeof(dp));
    return findans(0,nums.size(),nums);
    }
};