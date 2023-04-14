class Solution {
public:
    int dp[1001][1001];
    int findans(string &s,string &t,int i,int j)
    {
        if(i<0 | j<0)
            return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        if(s[i]==t[j])
        {
            return dp[i][j]=1+findans(s,t,i-1,j-1);
        }
        else
        {
            return dp[i][j]=max(findans(s,t,i-1,j),findans(s,t,i,j-1));
        }
    }
    int longestPalindromeSubseq(string s) {
        memset(dp,-1,sizeof(dp));
        string t=s;
        reverse(t.begin(),t.end());
        return findans(s,t,s.size()-1,s.size()-1);
    }
};