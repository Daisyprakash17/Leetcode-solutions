class Solution {
public:
    vector<pair<int,int>>vals;
    int n;
    void findans(vector<int>arr[],int node,int first)
    {
        
        queue<pair<int,int>>q;
        q.push({node,0}); 
        vector<int>vis(n,0);
        vis[node]=1;
        while(q.size()>0)
        {
            int val=q.front().first;
            int dis=q.front().second;
            q.pop(); 
            if(first)
                vals[val].first=dis;
            else
                vals[val].second=dis;
            
            for(auto i :arr[val])
                if(vis[i]==0)
                {
                    vis[i]=1;
                    q.push({i,dis+1});
                }
        }
    }
    int closestMeetingNode(vector<int>& e, int f, int s) {
          n=e.size();
        vector<int>arr[n];
        for(int i=0;i<n;i++)
        {
            if(e[i]!=-1)
            arr[i].push_back(e[i]);
            vals.push_back({-1,-1});
        } 
        findans(arr,f,1); 
        findans(arr,s,0);
        int ans=INT_MAX;
        int in=-1;
        for(int i=0;i<n;i++)
            if(vals[i].first>=0 && vals[i].second>=0)
            {
               if(ans> max(vals[i].first,vals[i].second))
               {
                    ans=max(vals[i].first,vals[i].second);
                   in=i;
               }
            }
        return in;
    }
};