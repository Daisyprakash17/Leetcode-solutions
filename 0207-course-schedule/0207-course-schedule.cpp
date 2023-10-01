class Solution {
public:
    
    bool canFinish(int n, vector<vector<int>>& p) {
       
        vector<vector<int>>v(n);
        vector<int>in(n,0);
        for(auto i:p)
        {
            v[i[0]].push_back(i[1]);
            in[i[1]]++;
        }
        int count=0;
        queue<int>q;
        for(int i=0;i<n;i++)
        {
            if(in[i]==0)
                q.push(i);
        }
        while(q.size()>0)
        {
            int node=q.front();
            q.pop();
            count++;
            for(auto i:v[node])
            {
                in[i]--;
                if(in[i]==0)
                    q.push(i);
            }
        }
        return count==n;
    }
};