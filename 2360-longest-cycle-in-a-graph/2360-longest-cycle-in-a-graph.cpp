class Solution {
public:
    void findans(vector<vector<int>>&arr,int node,int time,int& ans,vector<int>&vis,vector<int>&dvis){
        vis[node]=time;
        dvis[node]=1;
        for(auto i:arr[node]){
            if(vis[i]==0){
                // this is not visited
                findans(arr,i,time+1,ans,vis,dvis);
            }else if(dvis[i]==1){
                // so this is the cycle
                ans=max(ans,abs(vis[i]-vis[node])+1);
            }
        }
        dvis[node]=0;
    }
    int longestCycle(vector<int>& edges) {
            int n=edges.size();
        vector<vector<int>>arr(n);
        for(int i=0;i<n;i++)
        {
            if(edges[i]!=-1){
                arr[i].push_back(edges[i]);
            }
        }
        
        vector<int>vis(n,0);
        vector<int>dvis(n,0);
        int ans=-1;
        for(int i=0;i<n;i++){
            if(vis[i]==0){
                findans(arr,i,1,ans,vis,dvis);
            }
        }
        return ans;
    }
};