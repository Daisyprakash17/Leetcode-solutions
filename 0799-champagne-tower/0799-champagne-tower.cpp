class Solution {
public:
    double champagneTower(int p, int row, int col) {
        
        if(p==0)
            return 0;
        

        vector<vector<double>> dp(101 ,vector<double>(101,0.0)) ;
        dp[0][0]=p;
        
        for(int i=0;i<100;i++)
        {
            for(int j=0;j<=i;j++)
            {
            double val=dp[i][j];
                if(val>=1.0)
                {
                    val-=1.0;
                    dp[i][j]=1.0;
                }
                else
                    val=0.0;
                dp[i+1][j]+=val/2.0;
                dp[i+1][j+1]+=val/2.0;
            }
        } 
        return min(dp[row][col],1.0);
    }
};