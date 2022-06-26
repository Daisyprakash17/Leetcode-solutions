// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
	public:
	int dp[1001][1001];
	int findans(string &a,string &b,int n,int m)
	{
	    if(n==0 || m==0)
	    return 0;
	    if(dp[n][m]!=-1)
	    return dp[n][m];
	    
	    if(a[n-1]==b[m-1] && n!=m)
	    return dp[n][m]=1+findans(a,b,n-1,m-1);
	    else
	    return dp[n][m]=max(findans(a,b,n,m-1),findans(a,b,n-1,m));
	}
		int LongestRepeatingSubsequence(string a){
		    // Code here
		    memset(dp,-1,sizeof(dp));
		    return findans(a,a,a.size(),a.size());
		    
		}

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution obj;
		int ans = obj.LongestRepeatingSubsequence(str);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends