class Solution {
public:
    int minPathSum(vector<vector<int>>& v) {
        
        int n=v.size();
        int m=v[0].size();
        vector<vector<int>>temp(n,vector<int>(m,INT_MAX));
        temp[n-1][m-1]=v[n-1][m-1];
        for(int i=n-1;i>=0;i--)
        {
            for(int j=m-1;j>=0;j--)
            {
                 if(i+1<n && temp[i][j]>temp[i+1][j]+v[i][j])
                    temp[i][j]=temp[i+1][j]+v[i][j];
                    
                if(j+1<m && temp[i][j]>temp[i][j+1]+v[i][j])
                    temp[i][j]=temp[i][j+1]+v[i][j];
            }
        }
        
        return temp[0][0];
    }
};