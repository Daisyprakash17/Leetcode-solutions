class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& g) { 
        
        int n=g.size();
        int m=g[0].size();
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
                g[i][j]*=-1;
        }
        if(g[n-1][m-1]==-1|| g[0][0]==-1)
            return 0;
        g[n-1][m-1]=1;
        
        for(int i=n-1;i>=0;i--)
        {
                for(int j=m-1;j>=0;j--)
                {
                    if(g[i][j]!=-1)
                    {
                        long long  val=0;
                        if(i+1<n && g[i+1][j]!=-1)
                            val=(val+g[i+1][j])%2000000000;
                        if(j+1<m && g[i][j+1]!=-1)
                        {
                            val=(val+g[i][j+1])%2000000000;
                        }
                        g[i][j]+=val;
                    
                    }
                }
        } 
        return g[0][0];
    }
};