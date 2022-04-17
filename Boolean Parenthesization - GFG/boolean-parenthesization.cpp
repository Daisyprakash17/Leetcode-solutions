// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int dp[201][201][2];
    int findans(string &s,int i,int j,int val)
    { 
         if(i>j)
        return 0;
        if(i==j)
        {
            
            if((s[i]=='T' && val==1) ||(s[i]=='F' && val == 0))
            return 1;
            else
            return 0;
        }
        if(dp[i][j][val]!=-1)
        return dp[i][j][val];
        int count=0;
        for(int k=i+1;k<j;k+=2)
        {
            int lt=findans(s,i,k-1,1);
            int lf=findans(s,i,k-1,0);
            int rt=findans(s,k+1,j,1);
            int rf=findans(s,k+1,j,0);  
              if(s[k]=='&')
                {
                    if(val==1)
                    count+=lt*rt;
                    else 
                    count+=lt*rf+lf*rt+lf*rf;
                    count=count%1003;
                }
                else if(s[k]=='|')
                {
                    if(val==1)
                    {
                        count+=rt*lt+lt*rf+lf*rt;
                        
                    }
                    else
                    count+=lf*rf;
                    count=count%1003;
                }
                else if(s[k]=='^')
                {
                    if(val==1)
                    count+=lf*rt+lt*rf;
                    else
                    count+=lf*rf+lt*rt;
                    count=count%1003;
                }
        }
         return dp[i][j][val]=count;
    }
    int countWays(int n, string s){
        // code here
        memset(dp,-1,sizeof(dp));
     return findans(s,0,n-1,1); 
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        string S;
        cin>>S;
        
        Solution ob;
        cout<<ob.countWays(N, S)<<"\n";
    }
    return 0;
}  // } Driver Code Ends