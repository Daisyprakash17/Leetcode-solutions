class Solution {
public:
    int dp[1001][1001];
    int maxi=-1;
        int findans(vector<int>&a,vector<int>&b,int n,int m)
        {
            if(n==0 || m==0)
                return 0;
            
            if(dp[n][m]!=-1)
                return dp[n][m];
            if(a[n-1]==b[m-1])
                dp[n][m]=1+findans(a,b,n-1,m-1);
            else
                dp[n][m]=0;
            findans(a,b,n-1,m);
            findans(a,b,n,m-1);
            
            maxi=max(maxi,dp[n][m]);
            return dp[n][m];
    
    }
    int findLength(vector<int>& a, vector<int>& b) {
        int n=a.size();
        int m=b.size();
        memset(dp,-1,sizeof(dp));
          findans(a,b,n,m);
        return maxi;   
    }
};