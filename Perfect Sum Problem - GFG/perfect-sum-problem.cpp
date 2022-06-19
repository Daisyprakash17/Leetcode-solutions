// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{

	public:
	int dp[1001][1001];
	int mod=1000000007;
	int findans(int arr[],int sum,int n )
	{
	    
	    if(sum==0 && n==0)
	        return 1;
	    if(n==0  )
	        return 0;
	        
	   if(dp[n][sum]!=-1)
	   return dp[n][sum];
	   
	   if(arr[n-1]<=sum)
	   return dp[n][sum]=(findans(arr,sum-arr[n-1],n-1)+findans(arr,sum,n-1))%mod;
	   else
	   return dp[n][sum]=(findans(arr,sum,n-1))%mod;
	    
	}
	int perfectSum(int arr[], int n, int sum)
	{
        // Your code goes here
        memset(dp,-1,sizeof(dp));
        
        
        findans(arr,sum,n);
        return dp[n][sum];
	}
	  
};

// { Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.perfectSum(a, n, sum) << "\n";
	     
    }
    return 0;
}
  // } Driver Code Ends