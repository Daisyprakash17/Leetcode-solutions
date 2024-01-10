class Solution {
public:
int mod = 1e9+7;
    vector<int> dp;
    int rec(int node,vector<pair<int,int>> adj[],vector<int> &dist){
        if(node==1) return 1;
        if(dp[node]!=-1) return dp[node];
        int ans=0;
        for(auto it:adj[node]){
             if(dist[it.first]>dist[node]){
                 ans=(rec(it.first,adj,dist)%mod+ans%mod)%mod;
             }
        }
        return dp[node]=ans%mod;
    }
    int countRestrictedPaths(int n, vector<vector<int>>& edges) {
        vector<int> dist(n+1,INT_MAX);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
        q.push({0,n});
        vector<pair<int,int>> adj[n+1];
        for(auto it:edges){
            int u=it[0];
            int v=it[1];
            int wt=it[2];
            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
        }
        dist[n]=0;
        while(!q.empty()){
            int node=q.top().second;
            int d=q.top().first;
            q.pop();
            for(auto i:adj[node]){
                
                if(dist[i.first]>(d+i.second)){
                    dist[i.first]=d+i.second;
                    q.push({dist[i.first],i.first});
                }
            }
        }
        //int ans=0;
        // for(int i=1;i<=n;i++){
        //     cout<<i<<"->"<<dist[i]<<endl;
        // }
        dp = vector<int>(n+1,-1);
        return rec(n,adj,dist);
    }
};