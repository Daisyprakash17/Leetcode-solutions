class Solution {
public:
    // this is the code to print the longest commmon sub-sequence and also retunrning the length
    int dp[1001][1001];
    int findans(string &a,string &b,int n,int m)
    {
        
        if(n==0 || m==0)
        {
            return 0;
        }
        if(dp[n][m]!=-1)
            return dp[n][m];
        if(a[n-1]==b[m-1])
            return dp[n][m]=1+findans(a,b,n-1,m-1);
        else
            return dp[n][m]=max(findans(a,b,n,m-1),findans(a,b,n-1,m));
    }
    int longestCommonSubsequence(string a, string b) {
        int n=a.size();
        int m=b.size(); 
        memset(dp,-1,sizeof(dp));
         int ans= findans( a,b,n,m);
        
        string temp;
        int i=n;
        int j=m;
        while(i>0 && j>0)
        {
            if(a[i-1]==b[j-1])
            {
                temp+=a[i-1];
                i--;
                j--;
            }
            else
            {
                if(dp[i-1][j]>=dp[i][j-1])
                    i--;
                else
                    j--;
            }
        }
        reverse(temp.begin(),temp.end());
        cout<<temp<<endl;
        return ans;
    
    }
};