// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
		

	public:
	int dp[1001][1001];
	   int findans(string &a,string &b,int n,int m)
	   {
	       if(n==0 || m==0)
	       return 0;
	       if(dp[n][m]!=-1)
	            return dp[n][m];
	           
	       if(a[n-1]==b[m-1])
	       return dp[n][m]=1+findans(a,b,n-1,m-1);
	       else
	       return dp[n][m]=max(findans(a,b,n,m-1),findans(a,b,n-1,m));
	   }
	int minOperations(string a, string b) 
	{ 
	    // Your code goes here
	    int n=a.size();
	    int m=b.size();
	    memset(dp,-1,sizeof(dp));
	    int val=findans(a,b,n,m);
	    
	    return abs(n-val)+abs(m-val);
	} 
};

// { Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        string s1, s2;
        cin >> s1 >> s2;

	    Solution ob;
	    cout << ob.minOperations(s1, s2) << "\n";
	     
    }
    return 0;
}

  // } Driver Code Ends