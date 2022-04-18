// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
    public:
    //Function to find minimum number of attempts needed in 
    //order to find the critical floor.
     int dp[101][10001];
    int findans(int e,int f)
    {
        if(e==0 || f==0)
            return dp[e][f]=0;
        if(e==1 || f==1)
            return dp[e][f]=f;
        if(dp[e][f]!=-1)
            return dp[e][f];
        int mini=INT_MAX;
        for(int k=1;k<=f;k++)
        {
        
            int ans=1+max(findans(e-1,k-1),findans(e,f-k));
            mini=min(mini,ans);
        }
        return dp[e][f]=mini;
        }
    int eggDrop(int n, int k) 
    {
        // your code here
        
        memset(dp,-1,sizeof(dp));
        return findans(n,k);
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
        //taking eggs and floors count
        int n, k;
        cin>>n>>k;
        Solution ob;
        //calling function eggDrop()
        cout<<ob.eggDrop(n, k)<<endl;
    }
    return 0;
}
  // } Driver Code Ends