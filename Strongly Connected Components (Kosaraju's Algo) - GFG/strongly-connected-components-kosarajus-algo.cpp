//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find number of strongly connected components in the graph.
	void findscc(vector<vector<int>>&v,int node,vector<int>&disc,vector<int>&low,vector<int>&vis,vector<int>&instack,stack<int>&mystack,int& timer,int &ans)
{
    
    vis[node]=instack[node]=1;
    disc[node]=low[node]=timer++;
    mystack.push(node);
    
    for(auto i:v[node])
    {
         
        if(vis[i]==0)
        {
            findscc(v,i,disc,low,vis,instack,mystack,timer,ans);
            low[node]=min(low[node],low[i]);
        }else if(instack[i]==1)
        {
            low[node]=min(low[node],disc[i]);
        }
    }
    if(disc[node]==low[node])
    { 
        ans++;
        vector<int>temp;
        while(mystack.top()!=node)
        { 
            instack[mystack.top()]=0;
            mystack.pop();
        } 
            instack[mystack.top()]=0;
            mystack.pop();
        
    }
}
    int kosaraju(int n, vector<vector<int>>& v)
    {
        //code here
    vector<int>low(n,-1);
    vector<int>disc(n,-1);
    vector<int>vis(n,0);
    vector<int>instack(n,0);
    stack<int>mystack;
    int timer=0;
    int ans=0;
    for(int i=0;i<n;i++)
    {
        
        if(vis[i]==0)
        {
            findscc(v,i,disc,low,vis,instack,mystack,timer,ans);
        }
    }
    return ans;
    }
};

//{ Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<vector<int>> adj(V);

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends