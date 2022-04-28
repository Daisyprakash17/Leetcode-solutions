class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& v) {
        int n=v.size();
        vector<int>vis(n,-1);
        int count=0;
        queue<int>q;
        q.push(0);
        while(q.size()>0)
        {
            int val=q.front();
            q.pop();
            if(vis[val]==-1)
            {
                vis[val]=1;// visited
                count++;
                for(auto i:v[val])
                    if(vis[i]==-1)
                        q.push(i);
            }
        }
        
        return count==n;
    }
};