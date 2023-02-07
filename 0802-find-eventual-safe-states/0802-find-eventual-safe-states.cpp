class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& v) {
        
        
        
        int n=v.size();
        vector<int>in(n,0); // reverse in
        // in this i will traverse in graph by reveseing all the 
        // directed edges
        vector<int >arr[n];
        // so we have reverse all the edges
        for(int i=0;i<n;i++)
        {
            for(auto j:v[i]) 
              {
                    arr[j].push_back(i);
                    in[i]++;
                }
        }
          
            queue<int>q;
        for(int i=0;i<n;i++)
            if(in[i]==0)
                q.push(i);
        vector<int>ans;
        while(q.size()>0)
        {
            int node=q.front();
            q.pop();
            ans.push_back(node);
            for(auto i:arr[node])
            {
                in[i]--;
                if(in[i]==0)
                {
                    q.push(i);
                }
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};