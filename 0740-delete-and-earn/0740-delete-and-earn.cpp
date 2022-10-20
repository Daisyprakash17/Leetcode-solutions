class Solution {
public:
    map<int,int>m;
    int dp[20001];
    int findans(vector<int>&v,int i)
    {
        if(i<0)
            return 0;
        
        if(dp[i]!=-1)
            return dp[i];
        int val=0;
        if(i-1>=0 && v[i]==v[i-1]+1)
        {
            val=max(v[i]*m[v[i]]+findans(v,i-2),findans(v,i-1));
            
        }
        else
            val=v[i]*m[v[i]]+findans(v,i-1);
        return dp[i]=val;
    }
    int deleteAndEarn(vector<int>& nums) {
        vector<int>v;
        memset(dp,-1,sizeof(dp));
        for(auto i:nums)
            m[i]++;
        for(auto i:m)
            v.push_back(i.first);
        
        return findans(v,v.size()-1);
    }
};