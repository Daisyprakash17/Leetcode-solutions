class Solution {
public:
    int findans(vector<vector<int>>&arr,int node,map<int,int>&check,vector<int>&vis){
        
        vis[node]=1;
        int temp=0;
        for(auto i:arr[node]){
            if(vis[i]==0){
                temp+=findans(arr,i,check,vis);
            }
        }
        if(check[node] || temp>0)
            temp+=2;
        return temp;
    }
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<vector<int>>arr(n);
        for(auto i:edges)
        {
            arr[i[0]].push_back(i[1]);
            arr[i[1]].push_back(i[0]);
        }
        vector<int>vis(n,0);
        
        map<int,int>check;
        for(int i=0;i<n;i++){
            if(hasApple[i])
                check[i]=true;
        }
        
        
        int res=findans(arr,0,check,vis);
        if(res!=0)
            res-=2;
        return res;
            
    }
};