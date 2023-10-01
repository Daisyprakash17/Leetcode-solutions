class Solution {
public:
    bool check(vector<vector<int>>&v,int node,vector<int>&vis,vector<int>&dvis){
        
        vis[node]=1;
        dvis[node]=1;
        for(auto i:v[node])
        {
                if(vis[i]==0)
                {
                    if(check(v,i,vis,dvis)==true){ 
                            return true;
                    }
                } else if(dvis[i]==1)
                    return true;
        }
        dvis[node]=0;
        return false;
    }
    bool canFinish(int n, vector<vector<int>>& p) {
        vector<vector<int>>v(n);
        for(auto i:p)
            v[i[0]].push_back(i[1]);
        
        vector<int>vis(n,0),dvis(n,0);
        
        for(int i=0;i<n;i++)
        {
            if(vis[i]==0)
            {
                if(check(v,i,vis,dvis)==true)
                    return false;
            }
        }
        return true;
    }
};