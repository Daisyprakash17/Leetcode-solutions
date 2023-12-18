class Solution {
public:
    void fillval(vector<vector<int>>&arr,int node,vector<int>&vis,vector<int>&val,vector<int>&temp){
        vis[node]=1;
        temp.push_back(node);
        for(auto i:arr[node]){
            val[i]++;
            if(vis[i]==1)
                continue;
            fillval(arr,i,vis,val,temp);
        }
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>>arr(n);
        for(auto i:edges){
            arr[i[0]].push_back(i[1]);
            arr[i[1]].push_back(i[0]);
        }
        vector<int>val(n,0);
        vector<int>vis(n,0);
        int count=0;
        vector<int>temp;
        for(int i=0;i<n;i++){
            if(vis[i]==0){
            fillval(arr,i,vis,val,temp);
                int flag=1;
                for(auto i:temp){
                    if(val[i]!=temp.size()-1)
                        flag=0;    
                }
                if(flag==1)
                    count++;
                temp.clear();
            }
        }
        return count;
    }
};