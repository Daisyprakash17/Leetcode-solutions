class Solution {
public:
    
    // this is topological sort using bfs (kahn's algorithms)
    
    
    
    
    vector<int>findans(vector<int>arr[],int n)
    {
            vector<int>in(n,0);
        for(int i=0;i<n;i++)
            for(auto j:arr[i])
                in[j]++;
        queue<int>q;
        vector<int>final_ans;
        for(int i=0;i<n;i++)
            if(in[i]==0)
                q.push(i);// because these value have in degree as zero
        int count=0;
        while(q.size()>0)
        {
                int node=q.front();
            q.pop();
            final_ans.push_back(node);
            count++;
            for(auto i:arr[node])
            {
                
                in[i]--;
                if(in[i]==0)
                    q.push(i);
            }
        }
        if(count==n)
            return final_ans;
        vector<int>vv;
            return vv;
                
    }
    vector<int> findOrder(int n, vector<vector<int>>& v) {
        vector<int>arr[n];
        for(auto i:v)
            arr[i[0]].push_back(i[1]);
        vector<int>ans=findans(arr,n);
        reverse(ans.begin(),ans.end());
        return ans;
    }
};