class Solution {
public:
    
    void dfs(vector<vector<char>>&v,int i,int j,int n,int m)
    {
        if(i<0 || j<0 || i>=n || j>=m || v[i][j]=='0')
            return ;
        v[i][j]='0';
        dfs(v,i+1,j,n,m);
        dfs(v,i-1,j,n,m);
        dfs(v,i,j+1,n,m);
        dfs(v,i,j-1,n,m);
    }
    int numIslands(vector<vector<char>>& v) {
        int count=0;
        
        int n=v.size();
        int m=v[0].size();
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(v[i][j]=='1'){
                    count++;
                    dfs(v,i,j,n,m);
                }
            }
        }
        
        return count;
    }
};