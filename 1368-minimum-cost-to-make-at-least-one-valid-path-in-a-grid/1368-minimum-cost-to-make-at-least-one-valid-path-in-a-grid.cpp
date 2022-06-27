class Solution {
public:
    int minCost(vector<vector<int>>& t) {
        int n=t.size();
        int m=t[0].size();
        
        vector<vector<int>>v(n,vector<int>(m,INT_MAX));
        
            v[n-1][m-1]=0;
        queue<pair<int,int>>q;
         q.push({n-1,m-1});
        while(q.size()>0)
        {
            int i=q.front().first;
            int j=q.front().second;
            q.pop(); 
                    int val;
                if(i+1<n)
                {
                    if(t[i+1][j]==4)
                         val=0;
                    else
                        val=1;
                    if(v[i+1][j]>val+v[i][j])
                    {
                        v[i+1][j]= val+v[i][j];
                        q.push({i+1,j});
                    }
                }
                 if(i-1>=0)
                {
                    if(t[i-1][j]==3)
                        val=0;
                    else
                        val=1;
                     if(v[i-1][j]>val+v[i][j])
                     {  
                        v[i-1][j]= val+v[i][j];
                        q.push({i-1,j});
                     }
                 }
                 if(j+1<m)
                {
                     
                     if(t[i][j+1]==2)
                         val=0; 
                    else
                        val=1;
                     if(v[i][j+1]>val+v[i][j])
                     {
                     v[i][j+1]=val+v[i][j];
                         q.push({i,j+1});
                     }
                }
                 if(j-1>=0)
                {
                      if(t[i][j-1]==1)
                         val=0;
                    else
                         val=1;
                         
                        if(v[i][j-1]>val+v[i][j])
                         {
                     v[i][j-1]=val+v[i][j];
                         q.push({i,j-1});
                     }
                }
                    
        } 
       
        return v[0][0];
            
    }
};