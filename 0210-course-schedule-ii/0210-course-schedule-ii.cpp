class Solution {
public:
    bool check(vector<int>arr[],vector<int>&vis,vector<int>&dvis,int node)
    {
        
        vis[node]=1;
        dvis[node]=1;
        for(auto i:arr[node])
        {
            if(vis[i]==0)
            {    if(check(arr,vis,dvis,i))
                    return true;
            
            }
            else if(dvis[i]==1)
                return true;
        }
        dvis[node]=0;
        return false;
    }
    
    void topo(vector<int>arr[],vector<int>&vis,int node,vector<int>&ans)
    {
            vis[node]=1;
        for(auto i:arr[node])
            if(vis[i]==0)
                topo(arr,vis,i,ans);
        
        ans.push_back(node);
    }
    vector<int> findOrder(int n, vector<vector<int>>& v) {
        
        // before topo sort first we have to check for the cycle 
        // if there is the cycle then there will be no topo sort possible
        
        vector<int>arr[n];
        for(auto i:v)
        {
            arr[i[0]].push_back(i[1]);
        }
        vector<int>vis(n,0);
        vector<int>dvis(n,0);
        vector<int>ans;
        for(int i=0;i<n;i++)
        {
            if(vis[i]==0)
            {
                
                // if there is cycle then we will return 
                // the empty array which means that topo is not possible
                if(check(arr,vis,dvis,i))
                    return ans;
            }
        } 
        vector<int>vvis(n,0);
        for(int i=0;i<n;i++)
            if(vvis[i]==0)
        topo(arr,vvis,i,ans);
         
        return ans;
    }
};