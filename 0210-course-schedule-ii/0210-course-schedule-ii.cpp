class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& v) {
        
        vector<int >arr[n];
        vector<int>in(n,0);
        for(auto i:v){
            arr[i[0]].push_back(i[1]);
            in[i[1]]++;
        }
        vector<int>ans;
        
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
            ans.push_back(node);
            for(auto i:arr[node])
            {
                in[i]--;
                if(in[i]==0)
                    q.push(i);
            }
        }
        if(ans.size()<n)
        {
            vector<int>temp;
            return temp;
        }
        reverse(ans.begin(),ans.end());
        return ans;
        
    }
};