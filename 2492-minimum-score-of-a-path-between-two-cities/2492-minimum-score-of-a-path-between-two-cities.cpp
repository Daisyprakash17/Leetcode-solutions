class Solution {
public:
    void findans(int node,vector<pair<int,int>>arr[],vector<int>&vis,int &ans)
    {
    
    vis[node]=1;
        for(auto i:arr[node])
        {
            if(vis[i.first]==0)
            {
                findans(i.first,arr,vis,ans);
            }
            
                ans=min(ans,i.second);
        }
    }
    int minScore(int n, vector<vector<int>>& roads) {
        vector<pair<int,int>>arr[n+1];
        for(auto i:roads)
        {
            arr[i[0]].push_back({i[1],i[2]});
            arr[i[1]].push_back({i[0],i[2]});
        }
        vector<int>vis(n+1,0);
        int ans=INT_MAX;
        findans(1,arr,vis,ans);
        return ans;
    }
};