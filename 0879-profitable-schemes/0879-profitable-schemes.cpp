class Solution {
public:
    int dp[101][101][101];
    int mod=1e9+7;
    int findans(int i,int n,int mp ,vector<int>&g,vector<int>&p){
        if(i>=p.size())
            return mp<=0;
        if(mp<0)
            mp=0;
        if(dp[i][n][mp]!=-1)
            return dp[i][n][mp];
        
        int ans=0;
        if(g[i]<=n){
            ans=(ans+findans(i+1,n-g[i],mp-p[i],g,p))%mod;
        }
        ans=(ans+findans(i+1,n,mp,g,p))%mod;
        return dp[i][n][mp]=ans;
    }
    int profitableSchemes(int n, int mp, vector<int>& g, vector<int>& p) {
        memset(dp,-1,sizeof(dp));
        return findans(0,n,mp,g,p);
    }
    
    
};