// { Driver Code Starts
// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int dp[501][501];
    bool check(string &s,int i,int j)
    {
        while(i<=j)
        {
            if(s[i]!=s[j])
            return false;
            i++;
            j--;
        }
        return true;
    }
    int findans(string &s,int i,int j)
    {
        if(i>=j)
        return 0;
        if(check(s,i,j))
        return 0;
        
        if(dp[i][j]!=-1)
        return dp[i][j];
        
        int ans=INT_MAX;
        for(int k=i;k<j;k++)
        {
            int tempans=findans(s,i,k)+findans(s,k+1,j)+1;
            ans=min(ans,tempans);
        }
        return dp[i][j]=ans;
    }
    int palindromicPartition(string s)
    {
        // code here
        int n=s.size();
        memset(dp,-1,sizeof(dp));
        return findans(s,0,n-1);
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.palindromicPartition(str)<<"\n";
    }
    return 0;
}  // } Driver Code Ends