class Solution {
public:
    int dp[1001][1001];
    int findans(string &a,string &b,int n,int m)
    {
         if(n<0 && m<0)
            return 0;
        if((n<0 && m>=0) || (n>=0 && m<0))
        {
                int val=0;
            n++;
            m++;
            while(n--)
                val+=a[n];
            while(m--)
                val+=b[m];
            return val;
            
        }
         if(dp[n][m]!=-1)
            return dp[n][m];
        int res=0;
        if(a[n]==b[m])
            res=findans(a,b,n-1,m-1);
        else
            res=min((int)b[m]+findans(a,b,n,m-1),(int)a[n] +findans(a,b,n-1,m));
        
        return dp[n][m]=res;
        
    }
    int minimumDeleteSum(string s1, string s2) {
        memset(dp,-1,sizeof(dp));
        
        return findans(s1,s2,s1.size()-1,s2.size()-1);
    }
};