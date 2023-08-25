class Solution {
public:
    int dp[101][101][201];
    int findans(string &a,string &b,string &c,int i,int j,int k)
    { 
        if(k==c.size()) 
            return 1; 
        if(dp[i][j][k]!=-1)
            return dp[i][j][k];
        int ans=0;
        if(i<a.size() && a[i]==c[k]) 
            ans=ans|findans(a,b,c,i+1,j,k+1); 
        if(j<b.size() && b[j]==c[k]) 
            ans=ans|findans(a,b,c,i,j+1,k+1); 
        return dp[i][j][k]=ans;
    }
    bool isInterleave(string s1, string s2, string s3) {
        memset(dp,-1,sizeof(dp));
        if(s1.size()+ s2.size()!=s3.size())
            return false;
        return findans(s1,s2,s3,0,0,0);
    }
};