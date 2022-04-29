class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& m, vector<int>& t) {
        int ans=INT_MIN;
        vector<int>arr[n];
        for(int i=0;i<n;i++)
        {
            if(m[i]!=-1)
            {
                arr[m[i]].push_back(i);
            }
        }
        queue<pair<int,int>>q;
        q.push({headID,0});
        while(q.size()>0)
        {
            int node=q.front().first;
            int time=q.front().second;
            q.pop();
            ans=max(ans,time);
            for(auto i:arr[node])
                q.push({i,time+t[node]});
        }
        return ans;
    }
};