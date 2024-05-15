class Solution {
public:
    int dp[1001][1001];
    int findans(string &s,int i,int j){
        if(i>j)
            return 0;
        if(i==j)
            return 1;
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        int ans=0;
        if(s[i]==s[j]){
            ans=max(ans,2+findans(s,i+1,j-1));
        }
        // else if we want to explore all the other ways
        ans=max(ans,findans(s,i,j-1));
        ans=max(ans,findans(s,i+1,j));
        return dp[i][j]=ans;
    }
    int longestPalindromeSubseq(string s) {
        memset(dp,-1,sizeof(dp));
        return findans(s,0,s.size()-1);
    }
};