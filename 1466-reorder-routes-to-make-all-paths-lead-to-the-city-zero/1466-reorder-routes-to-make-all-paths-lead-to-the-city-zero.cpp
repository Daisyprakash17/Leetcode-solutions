class Solution {
public:
    
    void dfs(vector<int>v[],vector<int>rv[],int &count,vector<int>&vis,int node)
    {
        vis[node]=1;
        for(auto i:rv[node])
        {
            if(vis[i]==0)
            dfs(v,rv,count,vis,i);
        }
        for(auto i:v[node])
            if(vis[i]==0)
            {
                count++;
                dfs(v,rv,count,vis,i);
            }
        
            
    }
    int minReorder(int n, vector<vector<int>>& arr) {
        
        vector<int>v[n],rv[n];
        for(auto i:arr)
        {
            v[i[0]].push_back(i[1]);
            rv[i[1]].push_back(i[0]);
        }
        
        int count=0;
        vector<int>vis(n,0);
        dfs(v,rv,count,vis,0);
        return count;
        
    }
};