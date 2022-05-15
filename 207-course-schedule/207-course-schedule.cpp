class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& v) {
        
        
        vector<int>arr[n]; 
        vector<int>in(n,0);
        for(int i=0;i<v.size();i++)
        {
            arr[v[i][1]].push_back(v[i][0]); 
        }
        
        for(auto i:arr)
        {
            
            for(auto j:i)
                in[j]++;
        }
        queue<int>q;
        for(int i=0;i<n;i++)
        {
            if(in[i]==0)
                q.push(i);
        } 
        
        int count=0;
        while(q.size()>0)
        {
            auto it=q.front();
            q.pop();
            count++;
            for(auto i:arr[it])
            {
                in[i]--;
                if(in[i]==0)
                    q.push(i);
            }
        }
        return (n==count);
        
        
    }
};