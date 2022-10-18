class Solution {
public:
    int dp[2501][2501];
    int findans(vector<int>&v,int n,int pre)
    {
        if(n<0)
            return 0;
        if(pre!=-1 && dp[n][pre]!=-1)
            return dp[n][pre];
        int ans=0;
        // if it can be consider then also we have a choice to 
        // either considering that value or not considering that values
        if(pre==-1 || v[pre]>v[n])
            ans=max(ans,max(findans(v,n-1,pre),1+findans(v,n-1,n)));
        else
            ans=max(ans,findans(v,n-1,pre));
        if(pre==-1)
            return ans;
        return dp[n][pre]=ans;
    }
    int lengthOfLIS(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        
        return findans(nums,nums.size()-1,-1);
    }
};