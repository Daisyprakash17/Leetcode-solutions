// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    public:
    
    int dp[1001][1001];
    int maxi=-1;
    int findans(string &a,string &b,int n,int m)
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
    int longestCommonSubstr (string a, string b, int n, int m)
    {
        // your code here
         memset(dp,-1,sizeof(dp));
          findans(a,b,n,m);
        return maxi;  
    }
};

// { Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n, m; cin >> n >> m;
        string s1, s2;
        cin >> s1 >> s2;
        Solution ob;

        cout << ob.longestCommonSubstr (s1, s2, n, m) << endl;
    }
}
// Contributed By: Pranay Bansal
  // } Driver Code Ends