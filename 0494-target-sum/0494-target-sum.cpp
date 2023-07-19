class Solution {
public:
    int dp[20001][20];
    int findans(int i,int n,int sum,vector<int>&v)
    {
        if(i>=n)
        {
            if(sum==0)
                return 1;
            else
                return 0;
        }
        
        if(dp[sum][i]!=-1)
            return dp[sum][i];
        
        int ans=0;
        if(sum>=v[i])
            ans+=findans(i+1,n,sum-v[i],v);
        ans+=findans(i+1,n,sum,v);
        return dp[sum][i]=ans;
            
            
        }
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum=0;
        for(auto i:nums)
            sum+=i;
        target=abs(target);
        if((sum+target)%2!=0 ||sum<target)
            return 0; // this means that ans is not possible
        sum=abs((target+sum)/2);
        memset(dp,-1,sizeof(dp));
        return findans(0,nums.size(),sum,nums);
    }
};