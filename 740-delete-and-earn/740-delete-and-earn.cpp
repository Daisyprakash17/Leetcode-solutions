class Solution {
public:
    map<int,int>m;
    int findans(vector<int>&dp,int n,vector<int>&val)
    {
        if(n<=0)
            return 0; 
        if(dp[n]!=-1)
            return dp[n];
        
        int ans=0;
        if(m[val[n-1]-1]>0)
            ans=max(val[n-1]*m[val[n-1]]+findans(dp,n-2,val),findans(dp,n-1,val));
        else
        {
            ans=val[n-1]*m[val[n-1]]+findans(dp,n-1,val);
        }
        return dp[n]=ans;
    }
    int deleteAndEarn(vector<int>& nums) {
        
        for(auto i:nums)
            m[i]++;
        vector<int>val;
        for(auto i:m)
            val.push_back(i.first);
        int n=val.size();
        vector<int>dp(n+1,-1);
        return findans(dp,n,val);
    }
};