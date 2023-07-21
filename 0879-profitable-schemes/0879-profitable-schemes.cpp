class Solution {
public:
    int dp[101][101][101];
    int findans(int n,int cursum,int i,vector<int>&g,vector<int>&p)
    {
           
        if(i>=g.size() )
        {
            if(cursum>0)
                return 0;
            else
                return 1;
        }
            
        if(cursum<0)
            cursum=0; 
        if(dp[n][cursum][i]!=-1)
            return dp[n][cursum][i];
        int val=0;
        int mod=1e9+7;
        if(g[i]<=n)
            val=(findans(n-g[i],cursum-p[i],i+1,g,p)+findans(n,cursum,i+1,g,p))%mod;
        else
            val=findans(n,cursum,i+1,g,p)%mod;
        return dp[n][cursum][i]=val;
    }
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        memset(dp,-1,sizeof(dp));
        
        
        return findans(n,minProfit,0,group,profit);
    }
};