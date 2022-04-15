class Solution {
public:
    
   int dp[1001][1001];
    void findans(string a,string b,int n,int m)
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
        
        memset(dp,-1,sizeof(dp));
        findans(a,b,a.size(),b.size());
        
        
        string ans;
        int i=a.size();
        int j=b.size();
        while(i>0 && j>0)
        {
             if(a[i-1]==b[j-1])
            {
                ans+=a[i-1];
                 i--;
                j--;
                
            }
            else
            {
                // if not equal then 
                if(dp[i][j-1]<=dp[i-1][j])
                {
                    ans+=b[j-1];
                     j--;
                }
                else
                {
                    ans+=a[i-1];
                     i--;
                }
            }
        }
          while(i>0)
        {
            ans+=a[i-1];
            i--;
        }
        while(j>0)
        {
            ans+=b[j-1];
            j--;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};