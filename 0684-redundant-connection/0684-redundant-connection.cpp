class Solution {
public:
    int last=-1;
    vector<int>ans;
        map<pair<int,int>,int>m;
    void findans(vector<vector<int>>&arr,int node,vector<int>&low,vector<int>&disc,int timer,int par){
        low[node]=disc[node]=timer;
        timer++;
        for(auto i:arr[node]){
            if(i==par)
                continue;
            if(disc[i]==-1){
                findans(arr,i,low,disc,timer,node);
                low[node]=min(low[i],low[node]);
            }
            else{
                low[node]=min(low[node],disc[i]);
            }
            if(low[node]==low[i]){
                    // this is the cycle
                    if(m[{node,i}]>=last){
                        last=m[{node,i}];
                        ans.clear();
                        ans={node,i};
                    }if(m[{i,node}]>=last){
                        last=m[{i,node}];
                        ans.clear();
                        ans= {i,node};
                    }
                }
        }
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size()+1;
        vector<vector<int>>arr(n);
        int t=1;
        for(auto i:edges)
        {
            arr[i[0]].push_back(i[1]);
            arr[i[1]].push_back(i[0]);
            m[{i[0],i[1]}]=t++;
        }
        vector<int>low(n,-1);
        vector<int>disc(n,-1);
        int time=1;
        for(int i=0;i<n;i++){
            if(disc[i]==-1){
                findans(arr,i,low,disc,time,-1);
            }
        }
        return ans;
    }
};