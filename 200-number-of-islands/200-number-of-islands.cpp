class Solution {
public:
    
    void dfs(vector<vector<char>>&v,vector<vector<int>>& vis,int i,int j,int n,int m)
    {
            if(i<0 || j<0 || i>=n || j>=m || vis[i][j]==1  || v[i][j]=='0')
                return ; 
        vis[i][j]=1;
        
        dfs(v,vis,i+1,j,n,m);
        dfs(v,vis,i-1,j,n,m);
        dfs(v,vis,i,j+1,n,m);
        dfs(v,vis,i,j-1,n,m);
        
    }
    int numIslands(vector<vector<char>>& v) {
        int n=v.size();
        int m=v[0].size();
        vector<vector<int>>vis(n,vector<int>(m,-1));
        
        
        int count=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(v[i][j]=='1' && vis[i][j]==-1)
                {
                    dfs(v,vis,i,j,n,m);
                    count++;
                }
            }
        }
        return count;
        
    }
};