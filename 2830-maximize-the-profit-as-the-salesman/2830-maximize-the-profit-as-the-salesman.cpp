class Solution {
public:
    int dp[100000];
    int findans(vector<vector<int>>&v,int i)
    {
        if(i>=v.size())
            return 0;
        if(dp[i]!=-1)
            return dp[i];
        
        // if not considering the current offer
        int temp=findans(v,i+1);
        
        // if considering the current offer
        vector<int>tt={v[i][1]+1,0,0};
        auto it=lower_bound(v.begin(),v.end(),tt);
        temp=max(temp,v[i][2]+findans(v,it-v.begin()));
        return dp[i]=temp;
        
    }
    int maximizeTheProfit(int n, vector<vector<int>>& v) {
        sort(v.begin(),v.end());
        memset(dp,-1,sizeof(dp));
        return findans(v,0);
    }
};