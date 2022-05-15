class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& v) {
        
        vector<int>vis(n,0);
        vector<int>arr[n];
        for(auto i:v)
            arr[i[1]].push_back(i[0]);
        int counter=0;
        vector<int>in(n,0);
        for(auto i:arr)
            for(auto j:i)
                in[j]++;
        queue<int>q;
        for(int i=0;i<n;i++)
            if(in[i]==0)
            {
                
             q.push(i);
            cout<<i<<endl;
            }
        // we will push all the nodes whose in degree is zero in the queue
        
        while(q.size()>0)
        {
            int node=q.front();
            q.pop();
            counter++;
            for(auto i:arr[node])
            {
                in[i]--;
                if(in[i]==0)
                    q.push(i);
            }
        }
        if(counter==n)
            return true;
        else
            return false;
        
    }
};