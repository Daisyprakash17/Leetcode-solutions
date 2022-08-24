class Solution {
public:
    int minCost(int maxTime, vector<vector<int>>& e, vector<int>& p) {
       map<pair<int,int>,int >mm;
        for(auto i:e)
        {
            int u=i[0];
            int v=i[1];
            int cost=i[2];
            if(mm[{u,v}]==0)
                mm[{u,v}]=cost;
            if(mm[{v,u}]==0)
                mm[{v,u}]=cost;
            mm[{u,v}]=min(cost,mm[{u,v}]);
            mm[{v,u}]=min(cost,mm[{v,u}]);
        }
        int n=p.size();
        vector<pair<int,int>>arr[n];
        for(auto i:mm)
        { 
             arr[i.first.first].push_back({i.first.second,i.second}); 
            
        } 
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>q;
        // q is to store time cost node
        vector<int>v(n,INT_MAX);
        v[0]=p[0];
        q.push({0,{p[0],0}});
        
        while(q.size()>0)
        {
            pair<int,pair<int,int>> it=q.top();
            int time=it.first;
            int cost=it.second.first;
            int node=it.second.second;
            
            q.pop();
            if(v[node]<cost)
                continue;
            v[node]=cost;
            for(auto i:arr[node])
            {
                if(time+i.second<=maxTime && cost+p[i.first]<v[i.first])
                {
                    q.push({time+i.second,{cost+p[i.first],i.first}});
                }
            }
        }
         if(v[n-1]==INT_MAX)
             return -1;
             else
        return v[n-1];
    }
};