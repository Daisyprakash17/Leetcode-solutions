// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
        int dp[1001][1001];
        
        int findans(int w, int wt[], int val[], int n)
        {
             if(n<=0 || w<=0)
            return 0;
            if(dp[w][n]!=-1)
            return dp[w][n];
            if(wt[n-1]<=w)
            {
                return dp[w][n]=max(val[n-1]+findans(w-wt[n-1],wt,val,n-1),
                                    findans(w,wt,val,n-1));
                
            }
            else
            {
                    return dp[w][n]=findans(w,wt,val,n-1);
            }
        }
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       // Your code here
        
        memset(dp,-1,sizeof(dp));
        findans( W,wt,val,n);
        return dp[W][n];
    }
};

// { Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}  // } Driver Code Ends