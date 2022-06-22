class Solution {
public:
    map<int,int>m;
    int findans(vector<int>&dp,int n)
    {
        if(n<=0)
            return 0;
        if(dp[n]!=-1)
            return dp[n];
        
        return dp[n]=max(m[n]*n+findans(dp,n-2),findans(dp,n-1));
    }
    int deleteAndEarn(vector<int>& nums) {
        
        for(auto i:nums)
            m[i]++;
    vector<int>dp(10001,-1);
        sort(nums.begin(),nums.end());
        return findans(dp,10000);
    }
};