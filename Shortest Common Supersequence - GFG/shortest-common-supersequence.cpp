//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++


class Solution
{
    public:
    //Function to find length of shortest common supersequence of two strings.
    
     int dp[1000][1000];
    int findans(string &a,string &b,int i,int j)
    {
        if(i==a.size() || j==b.size())
            return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        int val=0;
        if(a[i]==b[j])
        {
            val=max(val,1+findans(a,b,i+1,j+1));
        }
        else
        {
        val=max(val,findans(a,b,i+1,j));
        val=max(val,findans(a,b,i,j+1));
        }
        return dp[i][j]=val;
    }
    int shortestCommonSupersequence(string X, string Y, int m, int n)
    {
        //code here
        memset(dp,-1,sizeof(dp));
        int res=findans(X,Y,0,0);
        return n+m-res;
    }
};

//{ Driver Code Starts.

int main()
{   
    
    int t;
    
    //taking total testcases
    cin >> t;
    while(t--){
    string X, Y;
    //taking String X and Y
	cin >> X >> Y;
	
	//calling function shortestCommonSupersequence()
	Solution obj;
	cout << obj.shortestCommonSupersequence(X, Y, X.size(), Y.size())<< endl;
    }
	return 0;
}


// } Driver Code Ends