class Solution {
public:
    map<string ,int>m; 
    int dp[302];
    int findans(string& s,int i)
    {
        
        if(i>=s.size())
            return 1;
        
        if(dp[i]!=-1)
            return dp[i];
        
        string temp;
        int ans=0;
        for(int j=i;j<s.size();j++)
        {
            temp+=s[j];
            if(m[temp])
                ans=max(ans,1&findans(s,j+1));
            
        }
        return dp[i]=ans;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
              
        memset(dp,-1,sizeof(dp));
        for(auto i:wordDict) 
            m[i]++;  
        return findans(s,0);
    }
};