class Solution {
public:
    int minimumTotal(vector<vector<int>>& v) {
        int n;
        n=v.size();
        vector<int>val(n,INT_MAX);
        
        for(int i=n-1;i>0;i--)
        {
            
            for(int j=0;j<=i;j++)
            {
                if(i==j)
                {
                    if(v[i][j]+v[i-1][j-1]<val[j-1])
                        val[j-1]=v[i][j]+v[i-1][j-1];
                }
                else if(j==0)
                {
                    if(v[i][j]+v[i-1][j]<val[j])
                        val[j]=v[i][j]+v[i-1][j];
                }
                else
                {
                    if(v[i][j]+v[i-1][j-1]<val[j-1])
                        val[j-1]=v[i][j]+v[i-1][j-1];
                     if(v[i][j]+v[i-1][j]<val[j])
                        val[j]=v[i][j]+v[i-1][j];
                }
            }
            v[i-1]=val;
            for(int k=0;k<n;k++)
                val[k]=INT_MAX;
            
        }
        
        return v[0][0];
    }
};