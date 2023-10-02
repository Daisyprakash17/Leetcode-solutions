//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
  void findarti(vector<int>v[],vector<int>&vis,int node,vector<int>&in,vector<int>&low,int& time,int par,map<int,int>&m)
{
    vis[node]=1;
    in[node]=low[node]=time++;
    int count=0;
    for(auto i:v[node])
    {
        if(par==i )
            continue;
        if(vis[i]==0)
        {
                    findarti(v,vis,i,in,low,time,node,m);
                    low[node]=min(low[node],low[i]);
                    if(low[i]>=in[node] && par!=-1)
                    {
                        m[node]++;
                    }
                    count++;
        }
        else
            low[node]=min(in[i],low[node]);
    }
    if(count>1 && par==-1)
        m[node]++;
}
    vector<int> articulationPoints(int n, vector<int>adj[]) {
         vector<int>in(n,-1);
        vector<int>low(n,-1);
        vector<int>vis(n,0);
        map<int,int>m;
        int time=1;
        for(int i=0;i<n;i++)
        {
            if(vis[i]==0)
            {
                findarti(adj,vis,i,in,low,time,-1,m);
            }
        
        }
        vector<int>ans;
        for(auto i:m)
            ans.push_back(i.first);

       
        
        if(ans.size()==0)
        ans.push_back(-1);
        sort(ans.begin(),ans.end());
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