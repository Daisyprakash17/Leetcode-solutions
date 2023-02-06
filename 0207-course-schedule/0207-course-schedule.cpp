class Solution {
public:
       bool  dfs(vector<int>arr[],vector<int>&vis,vector<int>&dvis,int node)
       {
           
           vis[node]=1;
           dvis[node]=1;
           for(auto i:arr[node])
           {
               if(vis[i]==0)
               {
                   if(dfs(arr,vis,dvis,i))
                       return  true ;// this is the cycle
               }
               else if(dvis[i]==1)
                   return true; // this is the cycle 
               
           }
           dvis[node]=0; // devisti the current traversal
           return false; // there is no cycle 
       }
    bool canFinish(int n , vector<vector<int>>& v) {
        vector<int >arr[n];
        
        for(auto i:v)
        {
            arr[i[0]].push_back(i[1]);
        }
        
        vector<int>vis(n,0);
        vector<int>dvis(n,0);
         
        for(int i=0;i<n;i++)
        {
            if(vis[i]==0)
            {
               if( dfs(arr,vis,dvis,i))
                   return false;
            }
        }
        return true;
    }
};