// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
  
  long long  dp[1001][1001];
  
  long long  findans(int s[],int n,int sum)
  {
      
       if(sum==0)
            return 1;
       if(n==0)
           return 0;
       if(dp[n][sum]!=-1)
           return dp[n][sum];
       if(s[n-1]<=sum)
       return dp[n][sum]=findans(s,n,sum-s[n-1])+findans(s,n-1,sum);
       else
       return dp[n][sum]=findans(s,n-1,sum);
       
       
  }
    long long int count(int S[], int n, int sum) {

        // code here.
        memset(dp,-1,sizeof(dp));
        findans(S,n,sum);
        return dp[n][sum];
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        int arr[m];
        for (int i = 0; i < m; i++) cin >> arr[i];
        Solution ob;
        cout << ob.count(arr, m, n) << endl;
    }

    return 0;
}  // } Driver Code Ends