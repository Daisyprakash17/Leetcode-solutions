class Solution {
public:
    int n,m;
    void fillit(vector<vector<int>>&v,int i,int j,set<pair<int,int>>&s)
    {
            if(i<0 || j<0 || i>=n || j>=m || v[i][j]!=1)
                return;
        v[i][j]=2;
        s.insert({i,j});
        fillit(v,i+1,j,s);
        fillit(v,i-1,j,s);
        fillit(v,i,j+1,s);
        fillit(v,i,j-1,s);
    }
    
    
    int shortestBridge(vector<vector<int>>& v) {
        
          n=v.size();
          m=n;
        int first=0;
        set<pair<int,int>>f,s;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                    if(v[i][j]==1 && first==0)
                    {
                        first++;
                        fillit(v,i,j,f);
                    
                        
                    }
                else
                {
                    fillit(v,i,j,s);
                }
            }
            
        }
        int ans=INT_MAX;
        
        for(auto i:f)
        {
            for(auto j:s)
            {
                ans=min(ans,abs(i.first-j.first)+abs(i.second-j.second)-1);
            }
        }
        return ans;
        
        
        
    }
};