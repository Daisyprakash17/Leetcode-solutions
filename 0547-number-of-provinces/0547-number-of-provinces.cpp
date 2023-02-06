class Solution {
public:
    void dfs(vector<int>arr[],vector<int>&vis,int node)
    {
        vis[node]=1;
        for(auto i:arr[node])
            if(vis[i]==0)
                dfs(arr,vis,i);
    }
    int findCircleNum(vector<vector<int>>& v) {
        int n=v.size();
        vector<int>arr[n];
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){ 
                if(v[i][j]==1){
                    arr[i].push_back(j);
                }
            }
        }
        
        vector<int>vis(n,0);
        int ans=0;
        for(int i=0;i<n;i++)
        {
            if(vis[i]==0)
            { 
                ans++;
                dfs(arr,vis,i);
            } 
        }
        return ans;
    }
};