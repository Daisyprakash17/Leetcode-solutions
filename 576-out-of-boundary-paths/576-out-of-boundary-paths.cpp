class Solution {
public:
    int dp[51][51][51];
    int n,m;
    int findans(int i,int j,int move)
    {
        if(i<0 || j<0 || i==n || j==m)
        {
            
            return 1;
        }
        if(move==0)
            return 0;
        if(dp[i][j][move]!=-1)
            return dp[i][j][move];
        
        int val=0;
        val=(val+findans(i+1,j,move-1))%1000000007;
        val=(val+findans(i,j+1,move-1))%1000000007;
        val=(val+findans(i,j-1,move-1))%1000000007;
        val=(val+findans(i-1,j,move-1))%1000000007;
        return dp[i][j][move]=val;
    }
    
    int findPaths(int row , int col, int maxMove, int i, int j) {
        memset(dp,-1,sizeof(dp));
        n=row;
        m=col;
        return findans(i,j,maxMove);
        
    }
};