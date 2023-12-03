//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    void findans(vector<int>arr[],int node,int par,vector<int>&vis,vector<int>&low,vector<int>&disc,int timer,vector<int>&ans){
        
        timer++;
        vis[node]=1;
        low[node]=timer;
        disc[node]=timer;
        int count=0;
        for(auto i:arr[node]){
            if(i==par)
            continue;
            if(vis[i]==0){
                findans(arr,i,node,vis,low,disc,timer,ans);
                low[node]=min(low[node],low[i]);
                if(low[i]>=disc[node] && par!=-1){
                    // this is the articulation point
                    ans.push_back(node);
                }
                count++;
            }else{
                low[node]=min(low[node],disc[i]);
            }
            
        }
        if(par==-1 && count>1)
            ans.push_back(node);
    }
    vector<int> articulationPoints(int V, vector<int>arr[]) {
        // Code here
        
        
        vector<int>vis(V,0);
        vector<int>low(V,0);
        vector<int>disc(V,0);
        vector<int>ans;
        int timer=1;
        for(int i=0;i<V;i++){
            if(vis[i]==0){
                findans(arr,i,-1,vis,low,disc,timer,ans);
            }
        }
        if(ans.size()==0)
        ans.push_back(-1);
        sort(ans.begin(),ans.end());
        auto it = unique(ans.begin(), ans.end());
        ans.resize(distance(ans.begin(), it));
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		vector<int> ans = obj.articulationPoints(V, adj);
		for(auto i: ans)cout << i << " ";
		cout << "\n";
	}
	return 0;
}
// } Driver Code Ends