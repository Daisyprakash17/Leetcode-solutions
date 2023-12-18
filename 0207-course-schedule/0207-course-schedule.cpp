class Solution {
public:
    bool check(vector<vector<int>>&arr,int node,vector<int>&vis,vector<int>&dvis){
        dvis[node]=vis[node]=1;
        for(auto i:arr[node]){
            if(vis[i]==0)
            {
                if(check(arr,i,vis,dvis)==true)
                    return true;
            }else if(dvis[i]==1)
                return true;
        }
        dvis[node]=0;
        return false;
    }
    bool canFinish(int n, vector<vector<int>>& edges) {
        vector<vector<int>>arr(n);
        for(auto i:edges)
        {
            arr[i[1]].push_back(i[0]);
        }
        vector<int>vis(n,0),dvis(n,0);
        for(int i=0;i<n;i++){
            if(vis[i]==0)
            {
                if(check(arr,i,vis,dvis)==true)
                    return false;
            }
        }
        return true;
    }
};