class Solution {
public:
    int dp[1001][1001];
    int findans(string &a,string &b,int n,int m)
    {
        
        if(n==0 || m==0)
        {
            return 0;
        }
        if(dp[n][m]!=-1)
            return dp[n][m];
        if(a[n-1]==b[m-1])
            return dp[n][m]=1+findans(a,b,n-1,m-1);
        else
            return dp[n][m]=max(findans(a,b,n,m-1),findans(a,b,n-1,m));
    }
    int longestCommonSubsequence(string a, string b) {
        int n=a.size();
        int m=b.size();  
        int dp[n+1][m+1];
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=m;j++)
                if(i==0 || j==0)
                    dp[i][j]=0;
            
            
        }
        
        for(int i=1;i<n+1;i++)
        {
            for(int j=1;j<m+1;j++) 
                if(a[i-1]==b[j-1])
                    dp[i][j]=1+dp[i-1][j-1];
            else
                dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
            
            
        }
        return dp[n][m];
        
    }
};