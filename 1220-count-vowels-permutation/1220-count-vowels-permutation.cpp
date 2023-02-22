class Solution {
public:
    int dp[20001][5];
    int mod=1e9+7;
    int findans(int val,int i,int n,vector<vector<int>>&v)
    {
        if(i>=n)
            return 1;
        if(dp[i][val]!=-1)
            return dp[i][val];
        
        long long temp=0;
        for(auto j:v[val])
            temp=(temp+findans(j,i+1,n,v))%mod;
        return dp[i][val]=temp;
    }
    int countVowelPermutation(int n) {
        memset(dp,-1,sizeof(dp));
        
        vector<vector<int>>v;
        v.push_back({1});
        v.push_back({0,2});
        v.push_back({0,1,3,4});
        v.push_back({2,4});
        v.push_back({0});
        
        long long ans=0;
        for(int i=0;i<5;i++)
        {
            ans=(ans+findans(i,1,n,v))%mod;
        }
        return  ans;
    }
};