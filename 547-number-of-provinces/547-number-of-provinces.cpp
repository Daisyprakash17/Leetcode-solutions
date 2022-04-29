class Solution {
public:
    int findCircleNum(vector<vector<int>>& v) {
        
        int count=0;
        int n=v.size();
        vector<int>vis(n,0); // not visited yet 
        vector<int>val[n];
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
                if(v[i][j]==1 && i!=j)
                val[i].push_back(j);
            
        }
        
         for(int i=0;i<n;i++)
        {
            if(vis[i]==0)
            {
                queue<int>q;
                q.push(i);
                count++;
                vis[i]=1;
                while(q.size()>0)
                {
                    int node=q.front();
                    q.pop();
                    for(auto i:val[node])
                        if(vis[i]==0)
                        {
                                vis[i]=1;
                                q.push(i);
                        }
                }
            }
        }
        return count;
    }
};