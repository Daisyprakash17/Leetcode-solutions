class Solution {
public:
    int dp[1001][1001];
    
    void findans(string &a,string &b,int n,int m)
    {
          for(int i=1;i<=n;i++)
        dp[i][0]=i;
        for(int j=1;j<=m;j++)
        dp[0][j]=j;
        dp[0][0]=0;
        for(int i=1;i<=n;i++)
        {
            
            for(int j=1;j<=m;j++)
            {
                if(a[i-1]==b[j-1])
                {
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else
                dp[i][j]=1+min(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    string shortestCommonSupersequence(string a, string b) {
        
        int n=a.size();
        int m=b.size();
        memset(dp,-1,sizeof(dp));
        
      
        findans(a,b,n,m);
         
        string s;
        int i=n;
        int j=m;
        while(i>0 && j>0)
        {
            
            if(a[i-1]==b[j-1])
            {
                s+=a[i-1];
                i--;
                j--;
            }
            else
            {
                if(dp[i][j-1]<=dp[i-1][j]){
                    s+=b[j-1];
                    j--;
                }
                else
                {
                    s+=a[i-1];
                    i--;
                    
                }
            }
        }
        while(i>0)
        {
            s+=a[i-1];
                    i--;
        }
        while(j>0)
        {
                    s+=b[j-1];
                    j--;
    }
        reverse(s.begin(),s.end());
        return s;
    
        
    }
};