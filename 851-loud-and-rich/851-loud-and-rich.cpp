class Solution {
public:
    vector<int> loudAndRich(vector<vector<int>>& e, vector<int>& val) {
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
        int n=val.size();
        vector<int>ans ;
        vector<int>in(n,0); 
        
        vector<vector<int>>arr(n);
        for(auto i:e)
        {
            int a=i[0];
            int b=i[1];
            arr[a].push_back(b);
            in[b]++;
        }
        map<int,int>m;
        for(int i=0;i<n;i++)
        {
            ans.push_back(val[i]);
            m[val[i]]=i;
            if(in[i]==0)
            {
                q.push({val[i],i});
            }
        }
        
        while(q.size()>0)
        {
            pair<int,int>p=q.top(); 
            q.pop(); 
            if(p.first<ans[p.second])
            ans[p.second]=p.first;
            for(auto i:arr[p.second])
               { 
                if(ans[i]>p.first)
                {
                    ans[i]=p.first; 
                    q.push({p.first,i});
                } 
                in[i]--;
                if(in[i]==0)
                    q.push({ans[i],i});
            }
        } 
        for(int i=0;i<n;i++)
            ans[i]=m[ans[i]];
        return ans;
    }
};