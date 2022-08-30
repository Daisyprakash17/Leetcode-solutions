class Solution {
public:
    int dp[1001];
    int findans(vector<int>&v,int t)
    {
        if(t==0)
            return 1;
        if(dp[t]!=-1)
            return dp[t];
        int val=0;
        for(auto i:v)
        {
            if(i<=t)
                val+=findans(v,t-i);
        }
        return dp[t]=val;
    }
    int combinationSum4(vector<int>& nums, int target) {
        memset(dp,-1,sizeof(dp));
        return findans(nums,target);
    }
};