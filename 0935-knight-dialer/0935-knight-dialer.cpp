class Solution {
public:
    int dp[5][4][5001];
    int mod=1000000007;
    int findans(int i,int j,int n)
    {
        if(i<0 || j<0 || i>=4 || j>=3 )
            return 0;
        if(i==3 &&(j==0 || j==2))
            return 0;
         if(n==0)
            return 1;
        if(dp[i][j][n]!=-1)
            return dp[i][j][n]; 
        int val=0;
        n--;
        val=(val+findans(i-2,j+1,n))%mod;
        val=(val+findans(i-1,j+2,n))%mod;
        val=(val+findans(i+1,j+2,n))%mod;
        val=(val+findans(i+2,j+1,n))%mod;
        val=(val+findans(i+2,j-1,n))%mod;
        val=(val+findans(i+1,j-2,n))%mod;
        val=(val+findans(i-1,j-2,n))%mod;
        val=(val+findans(i-2,j-1,n))%mod;
        return dp[i][j][n+1]=val;
    }
    int knightDialer(int n) {
        
        
        memset(dp,-1,sizeof(dp));
        int ans=0;
        for(int i=0;i<4;i++)
        {
            for(int j=0;j<3;j++)
            {
                ans=(findans(i,j,n-1)+ans)%mod;
             }
        }
        return ans;
    }
    
};