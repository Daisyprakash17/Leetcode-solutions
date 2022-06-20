// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function Template for C++

class Solution{
  public:
    int dp[1001][1001];
    int findans(int price[],int n,int l)
    {
        if(l==0 || n==0)
        return 0;
        
        if(dp[l][n]!=-1)
        return dp[l][n];
    if(n<=l)
    {
    return dp[l][n] =max(price[n-1]+findans(price,n,l-n),findans(price,n-1,l));
    }
    else
    {
        return dp[l][n]=findans(price,n-1,l);
    }
    }
    int cutRod(int price[], int n) {
        //code here
        
        memset(dp,-1,sizeof(dp));
        
    findans(price,n,n);
    return dp[n][n];
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}  // } Driver Code Ends