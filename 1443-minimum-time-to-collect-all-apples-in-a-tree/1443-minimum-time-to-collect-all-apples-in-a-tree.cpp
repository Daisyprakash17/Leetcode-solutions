class Solution {
public:
    vector<vector<int>>arr ;
    vector<bool >apple;
    int findans( int node,vector<int>&vis)
    {
            
        int ans=0;
        vis[node]=1;
         for(auto i:arr[node])
        {
             if(vis[i]==1)
                 continue;
            int val=findans( i,vis);
            if(val>0)
                ans+=val;
        }
         if(ans>0)
            return ans+2;
        if(apple[node]==true)
            return 2;
        else
            return 0; 
    }
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& a) {
        vector<vector<int>>arrr(n);
        vector<int>vis(n+1,0);
        for(auto i:edges)
        {
            arrr[i[0]].push_back(i[1]);
            arrr[i[1]].push_back(i[0]);
        }
        arr=arrr;
        apple=a;
        return max(findans( 0,vis)-2,0);
    }
};