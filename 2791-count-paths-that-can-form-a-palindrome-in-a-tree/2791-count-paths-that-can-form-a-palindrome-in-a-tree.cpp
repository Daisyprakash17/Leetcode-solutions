class Solution {
public:
    void findans(vector<vector<pair<int,char>>>&arr,map<int ,long long>&m,int cur,int node,long long  &ans)
    {
        
        // here will be the logic of finding the ans for the current node
        ans+=m[cur];
        
        for(int i=0;i<26;i++)
        {
            ans+=m[cur^(1<<i)];
        }
        
        m[cur]++;
        for(auto i:arr[node])
        {
            findans(arr,m,cur^(1<<(i.second-'a')),i.first,ans);
        }
        
    }
    long long countPalindromePaths(vector<int>& p, string s) {
        int n=p.size();
        vector<vector<pair<int,char>>>arr(n);
        
        for(int i=1;i<n;i++)
        {
            arr[p[i]].push_back({i,s[i]});
        }
        map<int,long long>m;
        int cur=0;
        long long ans=0;
        int node=0;
        findans(arr,m,cur,node,ans);
        return ans;
    }
};