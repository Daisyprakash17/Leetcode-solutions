// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
//User function template for C++

class Solution{   
public:
    int dp[101][10001];
    int findans(vector<int>&arr,int sum,int n)
    {
        
        if(sum==0)// if sum is zero empty set will make the sum
        return 1;
        if(n==0)// if n is zero that means that we cannot make the subset with the given sum
        return 0;
        
        
        if(dp[n][sum]!=-1)
        return dp[n][sum];
        
        if(arr[n-1]<=sum)
        return dp[n][sum]=(findans(arr,sum-arr[n-1],n-1) || findans(arr,sum,n-1));
        else
        return dp[n][sum]=findans(arr,sum,n-1);
    }
    bool isSubsetSum(vector<int>arr, int sum){
        // code here 
        memset(dp,-1,sizeof(dp));
        
        findans(arr,sum,arr.size());
        return dp[arr.size()][sum];
    }
};

// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
} 
  // } Driver Code Ends