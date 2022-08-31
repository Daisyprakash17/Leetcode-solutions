 
 
class Solution {
public:
    int n,m;
   void dfs(int i,int j,vector<vector<int>>&vis,vector<vector<int>>&heights,vector<vector<int>>&ans)
   {
             vis[i][j]=1;
         ans[i][j]++;
        if(i-1>=0 && vis[i-1][j]==0 &&heights[i-1][j]>=heights[i][j]) 
           dfs(i-1,j,vis,heights,ans); 
       
       if(j-1>=0 &&  vis[i][j-1]==0 &&heights[i][j-1]>=heights[i][j]) 
            dfs(i,j-1,vis,heights,ans); 
       
       if(i+1<n && vis[i+1][j]==0 && heights[i+1][j]>=heights[i][j])  
           dfs(i+1,j,vis,heights,ans); 
       
       if(j+1<m && vis[i][j+1]==0 && heights[i][j+1]>=heights[i][j])
           dfs(i,j+1,vis,heights,ans);
       
        
   }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
 
        vector<vector<int>>ans;
        
          n=heights.size();
            m=heights[0].size();
        vector<vector< int>>v(n,vector<int>(m,0));
        
         vector<vector<int>>vis(n,vector<int>(m,0)),dvis(n,vector<int>(m,0));
         
        // pacific
         cout<<vis[0][0]<<endl;
        for(int i=0;i<n;i++)
        {
            // all row
            if(vis[i][0]==0)
            dfs(i,0,vis,heights,v);
        }
         for(int i=0;i<m;i++)
        {
            if(vis[0][i]==0)
            dfs(0,i,vis,heights,v);
        }
         
          for(int i=0;i<n;i++)
        {
            // all row
              if(dvis[i][m-1]==0)
            dfs(i,m-1,dvis,heights,v);
        }
         for(int i=0;i<m;i++)
        {
            if(dvis[n-1][i]==0)
            dfs(n-1,i,dvis,heights,v);
        }
         
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(v[i][j]==2)
                    ans.push_back({i,j});
            }
        }
        return ans;
    }
};