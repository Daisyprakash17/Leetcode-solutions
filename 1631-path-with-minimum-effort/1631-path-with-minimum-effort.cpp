class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& b) {
         int n=b.size();
        int m=b[0].size();
        vector<vector<int>>v(n,vector<int>(m,INT_MAX));
        v[0][0]=0;
        queue<pair<int,int>>q;
        q.push({0,0});
        
        while(q.size()>0)
        {
            int i=q.front().first;
            int j=q.front().second;
            q.pop();
            if(i-1>=0 && v[i-1][j]>max(v[i][j],abs(b[i][j]-b[i-1][j])) )
            {
                v[i-1][j]=max(v[i][j],abs(b[i][j]-b[i-1][j])) ;
                q.push({i-1,j});
            }
            
             if(j-1>=0 && v[i][j-1]>max(v[i][j],abs(b[i][j]-b[i][j-1])) )
            {
                v[i][j-1]=max(v[i][j],abs(b[i][j]-b[i][j-1])) ;
                q.push({i,j-1});
            }
            
            if(i+1<n && v[i+1][j]>(max(v[i][j],abs(b[i][j]-b[i+1][j]))))
            {
                v[i+1][j]=max(v[i][j],abs(b[i][j]-b[i+1][j]));
                    q.push({i+1,j});
            }
              if(j+1<m && v[i][j+1]>(max(v[i][j],abs(b[i][j]-b[i][j+1]))))
            {
                v[i][j+1]=max(v[i][j],abs(b[i][j]-b[i][j+1]));
                    q.push({i,j+1});
            }
 
        }
        return v[n-1][m-1];
    }
};