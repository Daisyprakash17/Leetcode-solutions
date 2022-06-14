class Solution {
public:
    int dp[501][501];
    
    
    int findans(string &a,string &b,int i,int j)
    {
             if(i==0 || j==0)
            {
                 
                return  dp[i][j]=max(i,j);
                
            }
        
        if(dp[i][j]!=INT_MAX)
        {
             
            return dp[i][j];
        }
        if(a[i-1]==b[j-1])// if both the last character are same 
        {
             return  dp[i][j]=findans(a,b,i-1,j-1);
        }
            else
        {
            int first=findans(a,b,i-1,j);
            int second=findans(a,b,i,j-1); 
              return dp[i][j]=1+min(first,second);
        }
    }
    int minDistance(string a, string b) { 
        for(int i=0;i<501;i++)
        {
            for(int j=0;j<501;j++)
                dp[i][j]=INT_MAX;
        }
        int n=a.size();
        int m=b.size();
        findans(a,b,n,m);
        return dp[n][m];
    }
};