class Solution {
public:
    int networkDelayTime(vector<vector<int>>& e, int n, int k) {
        
        vector<vector<pair<int,int>>>arr(n+1);
        for(auto i:e)
        {
            arr[i[0]].push_back({i[1],i[2]});
        }
        vector<int>dis(n+1,INT_MAX);
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
        q.push({0,k});
        dis[k]=0;
        while(q.size()>0)
        {
            int node=q.top().second;
            int d=q.top().first;
            q.pop();
            
            for(auto i:arr[node])
            {
                if(dis[i.first]>d+i.second)
                {
                    dis[i.first]=d+i.second;
                    q.push({dis[i.first],i.first});
                }
            }
        }
        
        int ans=0;
        int flag=1;
        for(int i=1;i<=n;i++)
        {
            ans=max(ans,dis[i]);
        }
        if(ans==INT_MAX)
            return -1;
        return ans;
        
    }
};