class Solution {
public:
    int dp[100005];
    int findans(int i,int n,vector<int>&nums)
        {
            if(i>=n)
                return 1;
            if(dp[i]!=-1)
                return dp[i];
        
        int val=0;
        int temp;
        
            if(i+1<n && nums[i]==nums[i+1])
            {
                temp=findans(i+2,n,nums);
                val=max(val,temp);
            }
            if(i+2<n)
            {
                if((nums[i]==nums[i+1] && nums[i]==nums[i+2]) || (nums[i+1]==nums[i]+1 && nums[i+2]==nums[i]+2))
                    {
                    temp=findans(i+3,n,nums);
                    val=max(val,temp);
                    }
            }
       
        
        return dp[i]=val;
        }
    bool validPartition(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        
        return findans(0,nums.size(),nums);
    }
};