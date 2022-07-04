class Solution {
public:
    void findans(vector<vector<int>>&v,int node,vector<int>&vis,long long  &count)
    {
        count++;
        vis[node]=1;
        
        for(auto i:v[node])
            if(vis[i]==0)
            {
                findans(v,i,vis,count);
            }
    }
    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<vector<int>>v(n);
        
        for(auto i:edges)
        {
            v[i[0]].push_back(i[1]);
            v[i[1]].push_back(i[0]);
        }
        
        vector<int>vis(n,0);
        
        vector<long long >values;
        for(int i=0;i<n;i++)
        {
            
            if(vis[i]==0)
            {
                long long  count=0;
                findans(v,i,vis,count);
                values.push_back(count);
            }
        }
        long long ans=0;
        long long  no=n;
    
        for(int i=0;i<values.size();i++)
        {
             ans+=(no-values[i])*(values[i]);
            no-=values[i];
        }
        return ans;
    }
};