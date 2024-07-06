class Solution {
public:
    int dp[1001][1001];
    int findans(string &a,int i,int j){
       if(i>j)
        return 0;
    if(i==j)
        return 1;
    if(dp[i][j]!=-1)
        return dp[i][j];
    
    if(a[i]==a[j])
        dp[i][j]=2+findans(a,i+1,j-1);
    else
        dp[i][j]=max(findans(a,i+1,j),findans(a,i,j-1));
    return dp[i][j];
    }
    int longestPalindromeSubseq(string s) {
        memset(dp,-1,sizeof(dp));
        return findans(s,0,s.size()-1);
    }
};