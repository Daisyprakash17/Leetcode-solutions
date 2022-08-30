class Solution {
public:
    int dp[101];
    int findans(string s,int n)
    {
        if(n<=0)
            return 1;
        
        if(dp[n]!=-1)
            return dp[n];
        int sum=0;
        if(s[n-1]!='0')
        {
            sum+=findans(s,n-1);
        }
        if(n-1>0  )
        {
            if(s[n-2]=='1')
            sum+=findans(s,n-2);
            else if(s[n-2]=='2' && s[n-1]>='0' && s[n-1]<='6')
                sum+=findans(s,n-2);
        } 
        return dp[n]=sum;
    }
    int numDecodings(string s) {
        memset(dp,-1,sizeof(dp));
        return findans(s,s.size());
    }
};