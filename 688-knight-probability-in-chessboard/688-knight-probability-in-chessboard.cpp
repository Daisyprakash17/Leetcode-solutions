class Solution {
public:
     unordered_map<int, unordered_map<int, unordered_map<int, double>>>dp;
     double findans(int n,int k,int i,int j)
    { 
         if(i<0 || i>=n || j<0 || j>=n)
             return 0.0;
         if(k==0)
             return 1.0; 
          if(dp.count(i) && dp[i].count(j) && dp[i][j].count(k)) return dp[i][j][k];
        
         double total=0;
         total+=findans(n,k-1,i-2,j+1);
         total+=findans(n,k-1,i-1,j+2);
         total+=findans(n,k-1,i+1,j+2);
         total+=findans(n,k-1,i+2,j+1);
         total+=findans(n,k-1,i+2,j-1);
         total+=findans(n,k-1,i+1,j-2);
         total+=findans(n,k-1,i-1,j-2);
         total+=findans(n,k-1,i-2,j-1);
         

         return dp[i][j][k]=total/8;
    }
    double knightProbability(int n, int k, int row, int column) {
      
          return findans(n,k,row,column);
    }
};