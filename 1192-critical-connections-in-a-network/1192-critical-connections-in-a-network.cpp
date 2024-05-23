class Solution {
public:
    void findans(vector<vector<int>>&arr,int node,vector<int>&vis,vector<int>&desc,vector<int>&low,int timer,vector<vector<int>>&ans,int par){
        
        timer++;
        low[node]=desc[node]=vis[node]=timer;
        
        for(auto i:arr[node]){
            if(i==par)
                continue;
            if(vis[i]==0){
                // then we have to make the recursive call to find the bridges
                findans(arr,i,vis,desc,low,timer,ans,node);
                low[node]=min(low[node],low[i]);
                if(desc[node]<low[i])
                    ans.push_back({node,i});
            }
            else{
                low[node]=min(low[node],desc[i]);
            }
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        
        vector<vector<int>>arr(n);
        for(auto i:connections)
        {
            arr[i[0]].push_back(i[1]);
            arr[i[1]].push_back(i[0]);
        }
        vector<int>vis(n,0);
        vector<int>disc(n,INT_MAX);
        vector<int>low(n,INT_MAX);
        int timer=0;
        vector<vector<int>>ans;
        
        for(int i=0;i<n;i++){
            if(vis[i]==0){
                findans(arr,i,vis,disc,low,timer,ans,-1);
            }
        }
        return ans;
    }
};