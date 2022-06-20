// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{

	public:
	int dp[1001][1001];
	int findans(int coins[],int n,int sum)
	{
	    if(n==0)
	    return INT_MAX-1;
	    if(sum==0)
	    return 0;
	    
	    if(dp[n][sum]!=-1)
	    return dp[n][sum];
	    
	    if(coins[n-1]<=sum)
	    return dp[n][sum]=min(1+findans(coins,n,sum-coins[n-1]),findans(coins,n-1,sum));
	    else
	    return dp[n][sum]=findans(coins,n-1,sum);
	}
	int minCoins(int coins[], int M, int V) 
	{  
	    memset(dp,-1,sizeof(dp));
	    
	   findans(coins,M,V);
	   if(dp[M][V]==INT_MAX-1)
	   return -1;
	   return dp[M][V];
	} 
	  
};

// { Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int v, m;
        cin >> v >> m;

        int coins[m];
        for(int i = 0; i < m; i++)
        	cin >> coins[i];

      
	    Solution ob;
	    cout << ob.minCoins(coins, m, v) << "\n";
	     
    }
    return 0;
}
  // } Driver Code Ends