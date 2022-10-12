class Solution {
public:
    int dp[2002];
     bool check(int i,int j,string &s)
    {
        while(i<=j)
        {
            if(s[i]!=s[j])
                return false;
            i++;
            j--;
        }
        return true;
    }
    int findans(string &s,int i)
    {
        if(i>=s.size())
            return -1;
        if(dp[i]!=-1)
            return dp[i];
        int ans=INT_MAX;
        
        for(int j=i;j<s.size();j++)
        {
            
            if(check(i,j,s))
            {
                ans=min(ans,1+findans(s,j+1));
            }
        }
        return dp[i]=ans;
    }
    int minCut(string s) {
        memset(dp,-1,sizeof(dp));
        
        return findans(s,0);
        
    }
};