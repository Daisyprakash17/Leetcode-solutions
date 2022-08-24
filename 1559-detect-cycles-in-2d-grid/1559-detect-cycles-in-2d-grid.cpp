class Solution {
public:
    bool findans(vector<vector<char>>&v,pair<int,int>cur,pair<int,int>par,
                vector<vector<int>>&vis)
    { 
        vis[cur.first][cur.second]=1;
         int i=cur.first;
        int j=cur.second;
        char c=v[i][j];
        if(i-1>=0 && c==v[i-1][j])
        {
            if(vis[i-1][j]==0)
            {
                if(findans(v,{i-1,j},cur,vis))
                    return true;
            } else if(make_pair(i-1,j)!=par)
                return true; 
        }
        
        if(i+1<v.size()&& c==v[i+1][j])
        {
            if(vis[i+1][j]==0)
            {
                if(findans(v,{i+1,j},cur,vis))
                    return true;
            } else if(make_pair(i+1,j)!=par)
                return true;
        }
        
        if(j-1>=0&& c==v[i][j-1])
        {
            if(vis[i ][j-1]==0)
            {
                if(findans(v,{i ,j-1},cur,vis))
                    return true;
            } else if(make_pair(i,j-1)!=par)
                return true; 
        }
        
        if(j+1<v[0].size()&& c==v[i][j+1])
        {
            if(vis[i][j+1]==0)
            {
                if(findans(v,{i ,j+1},cur,vis))
                    return true;
            } else if(make_pair(i,j+1)!=par)
                return true; 
        }
        return false;
    }
    bool containsCycle(vector<vector<char>>& v) {
        int n=v.size();
        int m=v[0].size();
        
        vector<vector<int>>vis(n,vector<int>(m,0));
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(vis[i][j]==0)
                {
                    if(findans(v,make_pair(i,j),make_pair(-1,-1),vis))
                        return true;
                }
            }
        }
        return false;
    }
};