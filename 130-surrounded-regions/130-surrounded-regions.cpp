class Solution {
public:
    
    
    void fillit(vector<vector<char>>&v,int i,int j,int n,int m)
    {
        
        if(i<0 || j<0 || i>=n || j>=m || v[i][j]!='O')
            return ;
        
        v[i][j]='#'; // after bfs i will mark this as o and remaming all as X
        
        fillit(v,i+1,j,n,m);
        fillit(v,i-1,j,n,m);
        fillit(v,i,j-1,n,m);
        fillit(v,i,j+1,n,m);
    }
    void solve(vector<vector<char>>& v) {
        int n=v.size(); // rows
        int m=v[0].size(); // coloum 
        
        
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(i==0 || i==n-1 || j==0 || j==m-1)
                { 
                    if(v[i][j]=='O')
                    {
                         fillit(v,i,j,n,m);
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