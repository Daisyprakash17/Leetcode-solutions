class Solution {
public:
    vector<pair<int,int>>vals;
    int findans(vector<vector<int>>&v,vector<vector<int>>&vis,int i,int j, int pre)
    { 
        
        if(i<0  || j<0 || i>=v.size() || j>=v[0].size() || v[i][j]!=pre)
            return  1;
        if(vis[i][j]==1)
            return 0;
        vis[i][j]=1;
          int val=0;
            val+=findans(v,vis,i-1,j,v[i][j]); 
            val+=findans(v,vis,i+1,j,v[i][j]); 
            val+=findans(v,vis,i,j-1,v[i][j]); 
            val+=findans(v,vis,i,j+1,v[i][j]);     
      if(val>0)
          vals.push_back({i,j});
        
      return 0; 
    }
    vector<vector<int>> colorBorder(vector<vector<int>>& v, int row, int col, int color) {
        int n=v.size();
        int m=v[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        findans(v,vis,row,col,v[row][col]);
        for(auto i:vals)
            v[i.first][i.second]=color;
        return v;
    }
};