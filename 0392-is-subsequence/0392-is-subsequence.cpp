class Solution {
public:
    int dp[100][10000];
    int findans(string &a ,string &b,int i,int j)
    {
        if(i==a.size())
            return 1;
        if(j==b.size())
        return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        int res=0;
        if(a[i]==b[j])
            res=findans(a,b,i+1,j+1);
        else
            res=findans(a,b,i,j+1);
        return dp[i][j]=res;
    }
    bool isSubsequence(string s, string t) {
        memset(dp,-1,sizeof(dp));
        return findans(s,t,0,0);
    }
};