class Solution {
public:
    int dp[2501];
    int findans(vector<int>&v,int i)
    {
        if(i==v.size())
            return 0;
        if(dp[i]!=-1)
            return dp[i];
        int res=1;
        for(int j=i+1;j<v.size();j++)
        {
            if(v[j]>v[i])
                res=max(res,1+findans(v,j));
        }
        return dp[i]=res;
    }
    int lengthOfLIS(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        
        int ans=0;
        for(int i=0;i<nums.size();i++)
            ans=max(ans,findans(nums,i));
        return ans;
    }
};