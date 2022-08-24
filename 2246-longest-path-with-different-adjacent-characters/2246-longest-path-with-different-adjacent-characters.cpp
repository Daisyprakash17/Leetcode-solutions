class Solution {
public:
    int ans=1;
    int findans(vector<vector<int>>&v,int node,string &s)
    {
        vector<int>vals;
        for(auto i:v[node])
        {
            int val=findans(v,i,s);
            if(s[node]!=s[i])
                vals.push_back(val);
        }
        sort(vals.rbegin(),vals.rend());
        if(vals.size()>1)
        {
            ans=max(ans,vals[0]+vals[1]+1);
            return 1+max(vals[0],vals[1]);
        }
        else if(vals.size()==1)
        {
            ans=max(ans,1+vals[0]);
            return 1+vals[0];
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