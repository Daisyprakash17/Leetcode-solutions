class Solution {
public:
    void dfs(vector<vector<int>>&v,int i,int j,int n,int m)
    {
        if(i<0 || j<0 || i>=n || j>=m || v[i][j]!=1)
            return ;
        v[i][j]=0;
        dfs(v,i+1,j,n,m);
        dfs(v,i-1,j,n,m);
        dfs(v,i,j-1,n,m);
        dfs(v,i,j+1,n,m);
    }
    int numEnclaves(vector<vector<int>>& v) {
        int n=v.size();
        int m=v[0].size(); 
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(i==0 || j==0 || i==n-1 || j==m-1)
                {
                    if(v[i][j]==1) 
                        dfs(v,i,j,n,m);} 
            }
            
        }
        int ans=0;
        for(auto i:v)
            for(auto j:i)
                ans+=j;
        return ans;
    }
};