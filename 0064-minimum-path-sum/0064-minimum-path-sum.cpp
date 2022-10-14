class Solution {
public:
    int minPathSum(vector<vector<int>>& v) {
        int n=v.size();
        int m=v[0].size();
        vector<vector<int>>val(n,vector<int>(m,INT_MAX));
        val[n-1][m-1]=v[n-1][m-1];
        for(int i=n-1;i>=0;i--)
        {
            for(int j=m-1;j>=0;j--)
            {
                if(i-1>=0 && val[i-1][j]>v[i-1][j]+val[i][j])
                    val[i-1][j]=v[i-1][j]+val[i][j];
                
                if(j-1>=0 && val[i][j-1]>v[i][j-1]+val[i][j])
                     val[i][j-1]=v[i][j-1]+val[i][j];
        }
        } 
        return val[0][0];
    }
};