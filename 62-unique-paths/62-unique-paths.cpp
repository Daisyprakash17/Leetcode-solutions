class Solution {
public:
    int uniquePaths(int n, int m) {
        
        vector<vector<int>>v(n,vector<int>(m,0));
        v[0][0]=1;
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(j+1<m)
                    v[i][j+1]+=v[i][j];
                if(i+1<n)
                    v[i+1][j]+=v[i][j];
            }
        }
        return v[n-1][m-1];
    }
};