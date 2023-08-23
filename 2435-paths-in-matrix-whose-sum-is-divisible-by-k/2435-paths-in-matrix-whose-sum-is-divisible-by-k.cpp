class Solution {
public:
    int numberOfPaths(vector<vector<int>>& v, int k) {
         int n=v.size();
        int m=v[0].size();
        vector<vector<vector<int>>>t(n,vector<vector<int>>(m,vector<int>(k,0)));
         
        t[n-1][m-1][v[n-1][m-1]%k]++;
        int mod=1e9+7;
        
      
        for(int i=n-1;i>=0;i--)
        {
            for(int j=m-1;j>=0;j--)
            {
                if(i+1<n)
                {
                    for(int l=0;l<k;l++)
                    {
                        t[i][j][(l+v[i][j])%k]=(t[i][j][(l+v[i][j])%k]+t[i+1][j][l])%mod;
                    }
                }
                if(j+1<m)
                {
                    for(int l=0;l<k;l++)
                    {
                        t[i][j][(l+v[i][j])%k]=(t[i][j][(l+v[i][j])%k]+t[i][j+1][l])%mod;
                    }
                }
            }
        }
        
        return t[0][0][0];
        
    }
};