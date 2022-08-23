class Solution {
public: 
    void findans(vector<vector<pair<long long,long long>>>&arr,vector<long long >&v,int src)
    {
        priority_queue<pair<long long,long long>,vector<pair<long long,long long>>,greater<pair<long long,long long>>>q;
        v[src]=0;
        q.push({0,src});
        
        while(q.size()>0)
        {
            long long val=q.top().first;
            int node=q.top().second;
            q.pop();
            if(v[node]<val)
                continue;
            
            for(auto i:arr[node])
            {
                if(v[i.first]>val+i.second)
                {
                    v[i.first]=val+i.second;
                    q.push({v[i.first],i.first});
                }
            }
        }
    }
    long long minimumWeight(int n, vector<vector<int>>& edges, int src1, int src2, int dest) {
        vector<vector<pair<long long,long long>>>arr(n),arr1(n);
        
        
        for(auto i:edges)
        {
            int a=i[0];
            int b=i[1];
            int val=i[2];
            arr[a].push_back({b,val}); 
            arr1[b].push_back({a,val});
        }
        
        
        vector<long long >a(n, 1e11 ),b(n,1e11),d(n,1e11);
        
        
        findans(arr,a,src1);
        findans(arr,b,src2);
        findans(arr1,d,dest);
        
        long long  ans=1e11;
        for(int i=0;i<n;i++)
           if(a[i]!=1e11  && b[i]!=1e11  && d[i]!=1e11)
               ans=min(ans,a[i]+b[i]+d[i]);
                
        if(ans==1e11)
            return -1;
        else
        return ans;
        
    }
};