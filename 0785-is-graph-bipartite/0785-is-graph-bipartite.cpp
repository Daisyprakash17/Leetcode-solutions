class Solution {
public:
    bool dfs(vector<int>arr[],int node,int col,vector<int>&vis)
    {
        vis[node]=col;
        
        for(auto i:arr[node])
        {
            if(vis[i]==-1)
            {
                int temp= dfs(arr,i,(col+1)%2,vis);
                if(temp==0)
                    return false;
            }
            else if(vis[i]==col)
                return false;
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& v) {
        int n=v.size();
        vector<int>arr[n];
        for(int i=0;i<n;i++)
        {
                for(auto j:v[i])
                    arr[i].push_back(j);
        }
        int res=true;
        vector<int>vis(n,-1);
        // -1 denote not visited and no color
        for(int i=0;i<n;i++)
        {
            if(vis[i]==-1)
            {
               if(!dfs(arr,i,0,vis))
                   res=false;
            }
        }
        
        return res;
    }
};