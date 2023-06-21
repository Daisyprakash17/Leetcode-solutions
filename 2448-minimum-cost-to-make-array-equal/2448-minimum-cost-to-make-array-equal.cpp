class Solution {
public:
    bool cmp(pair<int,int>&a,pair<int,int>&b)
    {
        if(a.first==b.first)
            return a.second<b.second;
        return a.first<b.second;
    }
    long long minCost(vector<int>& nums, vector<int>& costs) {
        vector<pair<int,int>>v;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            v.push_back({nums[i],costs[i]});
        }
        sort(v.begin(),v.end());
        
        vector<long long >pre(n,0),suf(n,0);
        long long  sum=v[0].second;
        for(int i=1;i<n;i++)
        {
            long long  diff=v[i].first-v[i-1].first;
            pre[i]=diff*sum+pre[i-1];
            sum+=v[i].second;
        } 
        
        sum=v[n-1].second;
        for(int i=n-2;i>=0;i--)
        {
            long long  diff=v[i+1].first-v[i].first;
            suf[i]=diff*sum+suf[i+1];
            sum+=v[i].second;
        } 
        
        long long  ans=LONG_MAX;
        for(int i=0;i<n;i++)
            ans=min(ans,pre[i]+suf[i]);
        return ans;
    }
};