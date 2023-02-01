class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& r, int s, int t) {
        if(s==t)
            return 0;
        map<int,vector<int>>m;
        int n=r.size();
        for(int i=0;i<n;i++)
        {
            for(auto j:r[i])
            m[j].push_back(i);
        }
        vector<int>dis(n,INT_MAX);
        queue<pair<int,int>>q;
        for(auto i:m[s])
        { 
            q.push({i,1});
            cout<<i<<" "<<1<<endl;
            dis[i]=1;
        } 
        while(q.size()>0)
        {
            int node=q.front().first;
            int d=q.front().second;
            q.pop();
            if(dis[node]>d && dis[node]!=INT_MAX)
            {
                continue;
            } 
            for(auto i:r[node])
            {
                for(auto j:m[i] )
                    {
                    if(dis[j]>d+1 && j!=node)
                    {
                        q.push({j,d+1});
                        dis[j]=d+1;
                    }
                }
            }
        }
        int ans=INT_MAX;
        for(auto i:dis)
            cout<<i<<" ";
        cout<<endl;
        for(auto i:m[t])
        {
            ans=min(ans,dis[i]);
            
        }
        if(ans==INT_MAX)
            return -1;
        return ans;
    }
};