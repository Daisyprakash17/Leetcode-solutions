class Solution {
public:
    void dfs(int i,int j,bool &flag,vector<vector<int>>& grid,vector<vector<int>>& vis)
    {
        int n=grid.size(),m=grid[0].size();
        if(i==0 || j==0 || i==n-1 || j==m-1) flag=false;
        // cout<<i<<" "<<j<<" "<<flag<<endl;
        vis[i][j]=1;
        int di[]={+1,0,-1,0};
        int dj[]={0,+1,0,-1};

        for(int k=0;k<4;k++)
        {
            int ni=i+di[k];
            int nj=j+dj[k];

            if(ni>=0 && ni<n && nj>=0 && nj<m && !vis[ni][nj] && grid[ni][nj]==0)
            {
                dfs(ni,nj,flag,grid,vis);
            }
        }
    }
    int closedIsland(vector<vector<int>>& grid) {
        int ans=0;
        int n=grid.size();
        int m=grid[0].size();

        vector<vector<int>> vis(n,vector<int> (m,0));

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
               if(!vis[i][j] && grid[i][j]==0)
               {
                    bool flag=true;
                    dfs(i,j,flag,grid,vis);
                    if(flag) ans++;
               }
                
            }
        }
        return ans;
    }
};