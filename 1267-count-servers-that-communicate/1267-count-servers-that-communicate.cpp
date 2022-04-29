class Solution {
public:
    int countServers(vector<vector<int>>& g) {
        int n=g.size();
        int m=g[0].size();
        
        int final_ans=0;
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                    
                if(vis[i][j]==0 && g[i][j]==1)
                {
                    int count=0;
                    queue<pair<int,int>>q;
                    vis[i][j]=1;
                    q.push({i,j});
                    while(q.size()>0)
                    {
                        int a=q.front().first;
                        int b=q.front().second;
                         q.pop();
                        count++;
                        
                        for(int k=0;k<m;k++)
                            if(g[a][k]==1 && vis[a][k]==0)
                            {
                                vis[a][k]=1;
                                q.push({a,k});
                            }
                        for(int k=0;k<n;k++)
                            if(g[k][b]==1 && vis[k][b]==0)
                            {
                                vis[k][b]=1;
                                q.push({k,b});
                            }
                    }
                    if(count>1)
                        final_ans+=count;
                }
            }
        }
        return final_ans;
    }

    
};