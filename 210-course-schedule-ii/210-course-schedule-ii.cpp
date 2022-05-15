class Solution {
public:
    void getans(vector<int>&ans,int node, vector<vector<int>>&arr,vector<int>&vis)
    {
            vis[node]=1;
        
        for(auto i:arr[node])
            if(vis[i]==0)
            getans(ans,i,arr,vis);
        
        ans.push_back(node);
    }
    bool check(int n,vector<vector<int>>&arr )
    {
         
        vector<int>in(n,0);
        
        
        for(int i=0;i<arr.size();i++)
        {
            
            for(auto j:arr[i])
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
    vector<int> findOrder(int n, vector<vector<int>>& v) {
        
        vector<vector<int>>arr(n);
        for(auto i:v)
        {
             arr[i[0]].push_back(i[1]);
        }
        vector<int>ans;
        if(!check(n,arr))
            return ans;
        
        vector<int>vis(n,0);
         for(int i=0;i<n;i++)
        {
            if(vis[i]==0)
            {
                getans(ans,i,arr,vis);
            }
        }
        return ans;
        
        
    }
};