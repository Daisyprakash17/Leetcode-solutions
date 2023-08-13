class Solution {
public:
    int dp[1000][1000];
    int findans(string &a,string &b,int i,int j)
    {
        if(i==a.size() || j==b.size())
            return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        int val=0;
        if(a[i]==b[j])
        {
            val=max(val,1+findans(a,b,i+1,j+1));
        }
        else
        {
        val=max(val,findans(a,b,i+1,j));
        val=max(val,findans(a,b,i,j+1));
        }
        return dp[i][j]=val;
    }
    
    int longestPalindromeSubseq(string s) {
        memset(dp,-1,sizeof(dp));
        string t=s;
        reverse(t.begin(),t.end());
        return findans(s,t,0,0);
    }
};