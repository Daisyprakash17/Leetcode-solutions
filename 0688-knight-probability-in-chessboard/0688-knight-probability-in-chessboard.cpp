class Solution {
public:
    double dp[26][26][101];
    double findans(int n,int k,int i,int j)
    {
         if(i>=n || j>=n || i<0 || j<0 )
            return 0.0;
        
        
         if(k==0)
            return 1.0;
        
         cout<<to_string(dp[i][j][k])<<endl;
        if(to_string(dp[i][j][k])!="-nan")
            return dp[i][j][k];
        
          double total=0.0;
          total+=findans(n,k-1,i-2,j+1);
         total+=findans(n,k-1,i-1,j+2);
         total+=findans(n,k-1,i+1,j+2);
         total+=findans(n,k-1,i+2,j+1);
         total+=findans(n,k-1,i+2,j-1);
         total+=findans(n,k-1,i+1,j-2);
         total+=findans(n,k-1,i-1,j-2);
         total+=findans(n,k-1,i-2,j-1);
            cout<<total<<endl;
        return dp[i][j][k]=total/8;
    }
    double knightProbability(int n, int k, int row, int column) {
        memset(dp,-1.0,sizeof(dp));
        
        return findans(n,k,row,column);
    }
};