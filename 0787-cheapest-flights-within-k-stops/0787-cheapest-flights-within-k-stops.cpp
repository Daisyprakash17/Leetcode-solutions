class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        // so here we are replacing the k stops witht k+1 steps
        k++;
        
        vector<pair<int,int>>arr[n];
        for(auto i:flights)
        {
            arr[i[0]].push_back({i[1],i[2]});
        }
        pair<int,int>val;
        val.first=0;
        val.second=INT_MAX;
        vector<int>dis(n,INT_MAX);
        dis[src]=0;
        
        queue<pair<pair<int,int>,int>>q;
        q.push({{0,0},src});
        while(q.size()>0)
        {

            int steps=q.front().first.first;
            int d=q.front().first.second;
            int node=q.front().second;
            q.pop();
            
            for(auto i:arr[node])
            {
                if(steps+1<=k)
                {
                    if(dis[i.first]>d+i.second)
                    {
                        dis[i.first]=d+i.second;
                        q.push({{steps+1,dis[i.first]},i.first});
                    }
                }
            }
            
        }
        if(dis[dst]==INT_MAX)
            return -1;
        else
            
            return dis[dst];
        return 0;
    }
};