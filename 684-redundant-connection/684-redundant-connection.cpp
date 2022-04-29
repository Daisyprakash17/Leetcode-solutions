class Solution {
public:
    bool dfs(vector<int>arr[],int node,vector<int>&vis,int par)
    {
        vis[node]=1;
        for(auto i:arr[node])
            if(vis[i]==0)
            {
                if(dfs(arr,i,vis,node))
                    return true;
            }
        else if(par!=i)
            return true;
        return false;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& e) {
        
        int n=e.size();
        vector<int>arr[n+1];
        
        for(auto i:e)
        {
            int a=i[0];
            int b=i[1];
            arr[a].push_back(b);
            arr[b].push_back(a);
            vector<int>vis(n+1,0);
            if(dfs( arr,a,vis,-1))
                return i;
        }
        return { };
    }
};