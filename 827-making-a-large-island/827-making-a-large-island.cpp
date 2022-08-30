class Solution {
public:
       map<int,int>m;
    int final_ans=1;
    void findans(vector<vector<int>>&g,vector<vector<int>>&vis,int move,int& count,int i,int j)
    {
        if(i<0 || j<0 || i>=g.size() || j>=g.size() || vis[i][j]==1 || g[i][j]!=1)
            return ;
        count++;
        vis[i][j]=1;
        g[i][j]=move;
        findans(g,vis,move,count,i+1,j);
        findans(g,vis,move,count,i-1,j);
        findans(g,vis,move,count,i,j+1);
        findans(g,vis,move,count,i,j-1);
    }
    void getmax(int i,int j ,vector<vector<int>>&g )
    { 
        set<int>s;
        if(i-1>=0)
            s.insert(g[i-1][j]);
        if(i+1<g.size())
            s.insert(g[i+1][j]);
        if(j-1>=0)
            s.insert(g[i][j-1]);
        if(j+1<g.size())
            s.insert(g[i][j+1]);
        
        int sum=0;
        for(auto i:s)
            sum+=m[i];
        final_ans=max(final_ans,sum+1);
    }
    int largestIsland(vector<vector<int>>& g) {
     
        int n=g.size();
        vector<vector<int>>vis(n,vector<int>(n,0));
        
        
        int move=1;
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(vis[i][j]==0 && g[i][j]==1)
                {
                    int count=0;
                    findans(g,vis,move,count,i,j);
                    m[move]=count;
                    move++;
                    final_ans=max(final_ans,count+1);
                }
            }
        }
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(g[i][j]==0)
                {
                   getmax(i,j,g);
                }
            }
        }
        return min(final_ans,n*n);
    }
};