class Solution {
public:
    int dp[1000];
    int findans(vector<vector<int>>&p,int i)
    {
        if(i==p.size())
            return 0;
        if(dp[i]!=-1)
            return dp[i];
        
        int ans=1;
        for(int j=i+1;j<p.size();j++)
        {
            if(p[i][1]<p[j][0])
                ans=max(ans,1+findans(p,j));
        }
        return dp[i]=ans;
    }
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(),pairs.end());
        memset(dp,-1,sizeof(dp));
        int ans=0;
        for(int i=0;i<pairs.size();i++)
        {
            ans=max(ans,findans(pairs,i));
        }
        return ans;
    }
};