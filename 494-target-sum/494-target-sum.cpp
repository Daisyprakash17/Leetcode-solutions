class Solution {
public:
    int dp[21][20001];
        int findans(vector<int>&arr,int n,int sum)
        {
            if(sum==0 && n==0)
                return 1;
            if(n==0 && sum!=0)
                return 0;
            if(dp[n][sum]!=-1)
                return dp[n][sum];
            
            if(arr[n-1]<=sum)
            {
                return dp[n][sum]=(findans(arr,n-1,sum-arr[n-1])+findans(arr,n-1,sum));
            }
            else
                return dp[n][sum]=findans(arr,n-1,sum);
        }
    int findTargetSumWays(vector<int>& nums, int diff) {
          diff=abs(diff);
        memset(dp,-1,sizeof(dp));
        int sum=0;
        for(auto i:nums)
            sum+=i;
        if(sum<diff || (sum+diff)%2==1)
            return false;
        
        sum=(sum+diff)/2;
        
        findans(nums,nums.size(),sum);
        return dp[nums.size()][sum];
    }
};