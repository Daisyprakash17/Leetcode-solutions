class Solution {
public:
    int dp[1002][2];
    
    int findans(vector<int>&v,int n,int i,int flag)
    {
        if(i==n-1)
            return 1;
        if(dp[i][flag]!=-1)
            return dp[i][flag];
        int ans=0;
        if(flag==0)
        {
            // if we want negative diff
            if(v[i+1]-v[i]<0)
            {
                ans= 1+findans(v,n,i+1,1);
            }
            else
                ans=findans(v,n,i+1,0);
        }
        else
        {
            if(v[i+1]-v[i]>0)
                ans=1+findans(v,n,i+1,0);
            else
                ans=findans(v,n,i+1,1);
        }
        return dp[i][flag]=ans;
    }
    int wiggleMaxLength(vector<int>& nums) {
        int n=nums.size();
        
        int ans=-1;
        memset(dp,-1,sizeof(dp));
        
        // if want the first diff to be negative
        ans=max(ans,findans(nums,n,0,0));
        
        memset(dp,-1,sizeof(dp));
        
        // if want the first diff to be positive
        ans=max(ans,findans(nums,n,0,1));
        return ans;
    }
};