class Solution {
public:
    int findans(vector<vector<int>>&arr ,int node,vector<int>&vis,int col)
    {

                vis[node]=col;
        for(auto i:arr[node]){
            
        
            if(vis[i]==-1)
            {
                if(findans(arr,i,vis,(col+1)%2)==false)
                    return false;
            }else if(vis[i]==col)
                return false;
            }
        
    return true;    
    }
    bool possibleBipartition(int n, vector<vector<int>>& v) {
        vector<vector<int>>arr(n+1);
        for(auto i:v)
        {
            arr[i[0]].push_back(i[1]);
            arr[i[1]].push_back(i[0]);
        }
        
        vector<int>vis(n+1,-1);
        for(int i=1;i<=n;i++)
        {
                if(vis[i]==-1)
                    if(findans(arr,i,vis,0)==false)
                        return false;
        }
        return true;
    }
};