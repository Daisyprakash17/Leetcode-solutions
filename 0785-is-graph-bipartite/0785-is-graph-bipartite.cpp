class Solution {
public:
    bool isBipartite(vector<vector<int>>& g) {
        int n=g.size(); 
        vector<int>vis(n,0);
        vector<int>col(n,-1);
        for(int i=0;i<n;i++)
        {
            if(vis[i]==0)
            {
                queue<int>q;
                q.push(i);
                col[i]=0;
                while(q.size()>0)
                {
                    int node=q.front();
                    int c=col[node];
                    q.pop();
                    for(auto j:g[node])
                    {
                        if(vis[j]==0)
                        {
                            vis[j]=1;
                            q.push(j);
                            col[j]=(c+1)%2;
                        } else if(col[j]==c)
                            return false;
                        
                    }
                }
            }
        }
        return true; 
    }
};