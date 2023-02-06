class Solution {
public:
    int orangesRotting(vector<vector<int>>& v) {
        int n=v.size();
        int m=v[0].size();
        
        int time=0;
        queue<pair<pair<int,int>,int>>q;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(v[i][j]==2)
                    q.push({{i,j},0});
            }
        }
        
        while(q.size()>0)
        {
            int i=q.front().first.first;
            int j=q.front().first.second;
            int t=q.front().second;
             q.pop();
            time=max(time,t);
           if(i-1>=0 && v[i-1][j]==1)
           {
               v[i-1][j]=2;
               q.push({{i-1,j},t+1});
           }
            
           if(i+1<n && v[i+1][j]==1)
           {
               v[i+1][j]=2;
               q.push({{i+1,j},t+1});
           }
           if(j-1>=0 && v[i][j-1]==1)
           {
               v[i][j-1]=2;
               q.push({{i,j-1},t+1});
           }
           if(j+1<m && v[i][j+1]==1)
           {
               v[i][j+1]=2;
               q.push({{i,j+1},t+1});
           }
        }
        for(auto i:v)
            for(auto j:i)
                if(j==1)
                    return -1;
    return time;
    }
    
};