class Solution {
public:
    int dp[2001];
    int mod=1e9+7;
    int findans(string &s,int i)
    {
        if(i==s.size())
            return 0;
        
        if(dp[i]!=-1)
            return dp[i];
        int ans=0;
        vector<int>vis(26,0);
        for(int j=i;j<s.size();j++)
        {
            if(vis[s[j]-'a']==1)
                continue;
            vis[s[j]-'a']=1;
            ans=(ans+1+findans(s,j+1))%mod;
        }
        return dp[i]=ans;
    }
    int distinctSubseqII(string s) {
        memset(dp,-1,sizeof(dp));
        return findans(s,0);
    }
};