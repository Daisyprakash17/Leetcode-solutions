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
        for(int k=i+1;k<=j;k++)
        {
            int temp=0;
            if(dp[i][k-1]!=-1)
            temp+=dp[i][k-1];
            else
            temp+=findans(s,i,k-1);
            
            if(dp[k][j]!=-1)
            temp+=dp[k][j];
            else
            temp+=findans(s,k,j);
            
            ans=min(ans,temp+1);
        }
        return dp[i][j]=ans;
    }
    int palindromicPartition(string str)
    {
        // code here
        memset(dp,-1,sizeof(dp));
        return findans(str,0,str.size()-1);
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