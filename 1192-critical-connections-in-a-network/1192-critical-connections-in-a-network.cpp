class Solution {
public:
    vector<int>arr[100000];
        int t=0;
    void findans(int node,vector<int>&disc,vector<int>&low,vector<int>&p,vector<vector<int>>&ans)
    {
        t++;
        disc[node]=t;
        low[node]=t;
        
        for(auto i:arr[node])
        {
            if(disc[i]==-1)
            {
                // if this node is not visited yet
                p[i]=node;
                findans(i,disc,low,p,ans);
                low[node]=min(low[node],low[i]);
                
                if(low[i]>disc[node])
                {
                    // if child nodes low values is bigger the current 
                    // nodes discovery time then this is the bridge
                    ans.push_back({node,i}); 
                }
            }
            else if(i!=p[node])
            {
                // if node is visited and node is not the 
                // parent of the current node 
                // then we have to update the low value of the current node
                low[node]=min(low[node],disc[i]);
            }
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& v) {
        
        for(auto i:v)
        {
            arr[i[0]].push_back(i[1]);
            arr[i[1]].push_back(i[0]);
        }
        vector<int>p(n,-1),disc(n,-1),low(n,-1);
        vector<vector<int>>ans;
        for(int i=0;i<n;i++)
            if(disc[i]==-1)
        findans(i,disc,low,p,ans);
        return ans;
    }
};