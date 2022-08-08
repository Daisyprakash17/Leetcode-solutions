class Solution {
public:
    
    int dp[50000];
    
    int findans(vector<pair<int,int>>&v,vector<int>&p,int i)
    {
        if(i>=v.size())
            return 0;
        
        if(dp[i]!=-1)
            return dp[i];
        
        int ans=0;
        auto it=lower_bound(v.begin(),v.end(),make_pair(v[i].second,0));
        int in=v.size();
        if(it!=v.end())
            in=it-v.begin();
         ans=max(p[i]+findans(v,p,in),findans(v,p,i+1));
         return dp[i]=ans;
    }
    int jobScheduling(vector<int>& s, vector<int>& e, vector<int>& p) {
        vector<pair<int,int>>v;
        map<pair<int,int>,int>m;
        for(int i=0;i<s.size();i++)
        {   
             v.push_back({s[i],e[i]});
             m[{s[i],e[i]}]=max(p[i],m[{s[i],e[i]}]);
        }
        sort(v.begin(),v.end()); 
        for(int i=0;i<v.size();i++)
            p[i]=m[{v[i].first,v[i].second}];
        memset(dp,-1,sizeof(dp));
        return findans(v,p,0);
        return 0;
    }
};