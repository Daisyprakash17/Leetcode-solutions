class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& v) {
        int n=v.size();
        vector<vector<int>>ans(n,vector<int>(n,INT_MAX));
        ans[n-1]=v[n-1];
        
        for(int i=n-1;i>0;i--)
        {
            
            for(int j=0;j<n;j++)
            {
                if(j-1>=0 && ans[i-1][j-1]>=ans[i][j]+v[i-1][j-1])
                    ans[i-1][j-1]=ans[i][j]+v[i-1][j-1];
                    
                 if(ans[i-1][j]>=ans[i][j]+v[i-1][j])
                    ans[i-1][j]=ans[i][j]+v[i-1][j];
                
                  if(j+1<n && ans[i-1][j+1]>=ans[i][j]+v[i-1][j+1])
                    ans[i-1][j+1]=ans[i][j]+v[i-1][j+1];
            } 
        }
        
        
        return *min_element(ans[0].begin(),ans[0].end());
    }
};