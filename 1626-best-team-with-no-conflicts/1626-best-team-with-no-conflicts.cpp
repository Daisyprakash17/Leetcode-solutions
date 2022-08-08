class Solution {
public:
    int dp[1001][1001];
    int findans(vector<pair<int,int>>&a,int n,int pre)
    {
        if(n>=a.size())
            return 0;
        
        if(dp[n][pre]!=-1)
            return dp[n][pre];
        
        if(a[n].second>=pre)
        {
            // is age is greater or equal
            return dp[n][pre]=max(a[n].first+findans(a,n+1,a[n].second),findans(a,n+1,pre));
        }
        else
            return dp[n][pre]=findans(a,n+1,pre);
      
    }
    
    
    int bestTeamScore(vector<int>& s, vector<int>& a) {
        vector<pair<int,int>>v;
        int n=a.size();
        for(int i=0;i<n;i++)
        {
            v.push_back({s[i],a[i]});
        }
        sort(v.begin(),v.end()); 
        memset(dp,-1,sizeof(dp));
        return findans(v,0,0);
    }
};