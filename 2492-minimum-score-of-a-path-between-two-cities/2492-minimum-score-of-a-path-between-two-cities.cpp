class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>>arr(n+1);

        for(auto i:roads){
            arr[i[0]].push_back({i[1],i[2]});
            arr[i[1]].push_back({i[0],i[2]});
        }
        
        vector<int>dis(n+1,INT_MAX);
        dis[1]=INT_MAX;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
        q.push({INT_MAX,1});
        while(q.size()>0){
            int node=q.top().second;
            int d=q.top().first;
            q.pop();
            for(auto it:arr[node]){
                if(dis[it.first]>min(it.second,d)){
                    dis[it.first]=min(it.second,d);
                    q.push({dis[it.first],it.first});
                }
            }
        }
        return dis[n];
    }
};