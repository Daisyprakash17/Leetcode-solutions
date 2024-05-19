class Solution {
public:
    void findans(vector<vector<int>>&arr,vector<int>&vis,int node,int &count){
        
        vis[node]=1;
        count++;
       for(auto i:arr[node]){
           if(vis[i]==0)
               findans(arr,vis,i,count);
       } 
    }
    int removeStones(vector<vector<int>>& stones) {
        int n=stones.size();
        vector<vector<int>>arr(n);
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(stones[i][0]==stones[j][0] || stones[i][1]==stones[j][1])
                {
                    arr[i].push_back(j);
                    arr[j].push_back(i);
                }
            }
        }
        vector<int>vis(n,0);
        
        int ans=0;
        for(int i=0;i<n;i++){
            if(vis[i]==0){
                int temp=0;
                findans(arr,vis,i,temp);
                ans+=temp-1;
            }
        }
        return ans;
    }
};