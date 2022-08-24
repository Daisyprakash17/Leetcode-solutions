class Solution {
public:
    int ans=1;
    int findans(vector<vector<int>>&v,int node,string &s)
    {
        vector<int>vals;
         priority_queue<int,vector<int>,greater<int>>q;
        for(auto i:v[node])
        {
            int val=findans(v,i,s);
            if(s[node]!=s[i])
            {
                q.push(val);
                if(q.size()>2)
                    q.pop();
            }
        } 
        
        if(q.size()==2)
        {
            int first=q.top();
            q.pop();
            int second=q.top();
            q.pop();
            ans=max(ans,first+second+1);
            return 1+max(first,second);
        }
        else if(q.size()==1)
        {
            int first=q.top();
            q.pop();
            ans=max(ans,1+first);
            return 1+first;
        }
        else
            return 1;
    }
    int longestPath(vector<int>& parent, string s) {
            int n=parent.size();
        vector<vector<int>>arr(n);
        
        for(int i=1;i<n;i++)
        {
            arr[parent[i]].push_back(i);
        }
        
        findans(arr,0,s);
        return ans;
    }
};