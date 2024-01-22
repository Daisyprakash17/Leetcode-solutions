class Solution {
public:
    long long  ans=0;
    void findans(vector<vector<int>>&arr,int t,int target,long long  cur,int node,vector<int>&vis){
        
        vis[node]=1;   
        long long  count=0;
            for(auto i:arr[node])
                if(vis[i]==0)
                    count++;
    if(node==target){
            
        if(t==0 || count==0){
            
            ans=cur;
            return ;
        }
        }
    
        if(t>0){
            
            
            for(auto i:arr[node]){
                if(vis[i]==0){
                    findans(arr,t-1,target,cur*count,i,vis);
                }
            }
        }
        
    }
    double frogPosition(int n, vector<vector<int>>& edges, int t, int target) {
      double cur= 1.0;
        
        vector<vector<int>>arr(n+1);
        for(auto i:edges)
        {
            arr[i[0]].push_back(i[1]);
            arr[i[1]].push_back(i[0]);
        }
        vector<int>vis(n+1,0);
        findans(arr,t,target,cur,1,vis);
        if(ans==0.0)
            return ans;
        cout<<setprecision(6);
        return 1.0/(ans);
        
    }
};