class Solution {
public:
    int n,m;
    void findans(vector<vector<int>>&vis,int i,int j,int &val,int &ans)
    {
        if(i<0 || i>=n || j<0||j>=m   )
            return ;
        if(vis[i][j]==0)
            return ;
        vis[i][j]=0;
        val++;
        ans=max(ans,val);
        findans(vis,i+1,j,val,ans);
        findans(vis,i-1,j,val,ans);
        findans(vis,i,j+1,val,ans);
        findans(vis,i,j-1,val,ans);
    }
    int maxAreaOfIsland(vector<vector<int>>& v) {
          n=v.size();
         m=v[0].size();
        vector<vector<int>>vis(n,vector<int>(m,-1));
        int ans=0; 
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if( v[i][j]==1)
                {
                    int zero=0;
                     findans(v,i,j,zero,ans);
                }
            }
        }
        return ans;
    }
};