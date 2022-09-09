class Solution {
public:
    int dp[50][50][51];
    int mod=1000000007;
    int findans(int i,int j,int moves,int r,int c)
    {
        if(i<0 || i>=r || j<0 || j>=c)
            return 1;
        if(moves==0)
            return 0;
        
        if(dp[i][j][moves]!=-1)
            return dp[i][j][moves];
        
        int val=0;
        val=(val+findans(i-1,j,moves-1,r,c))%mod;
        val=(val+findans(i+1,j,moves-1,r,c))%mod;
        val=(val+findans(i,j-1,moves-1,r,c))%mod;
        val=(val+findans(i,j+1,moves-1,r,c))%mod;
        return dp[i][j][moves]=val;
            
    }
    int findPaths(int m, int n, int moves, int r, int c) {
        memset(dp,-1,sizeof(dp));
        
        return findans(r,c,moves,m,n);
    }
};