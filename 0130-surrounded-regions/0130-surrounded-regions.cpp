class Solution {
public:
    void dfs(vector<vector<char>>&v,int i,int j,int n,int m)
    {
        if(i<0 || j<0 || i>=n || j>=m || v[i][j]!='O')
            return ;
        v[i][j]='#';
        dfs(v,i-1,j,n,m);
        dfs(v,i+1,j,n,m);
        dfs(v,i,j-1,n,m);
        dfs(v,i,j+1,n,m);
    }
    void solve(vector<vector<char>>& v) {
        int n=v.size();
        int m=v[0].size();
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(i==0 || j==0 || i==n-1 || j==m-1)
                {
                    if(v[i][j]=='O')
                    { 
                        dfs(v,i,j,n,m);
                    }
                }
            }
        }
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(v[i][j]=='#')
                    v[i][j]='O';
                else 
                    v[i][j]='X';
            }
        }
    }
};