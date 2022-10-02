class Solution {
public:
    int dp[101];
    int findans(string &s,int n,int i)
    {
        if(i==n)
            return 1;
        
        if(s[i]=='0')
            return 0;
        if(dp[i]!=-1)
            return dp[i];
         int val=0;
        // this for single digit 
            val+=findans(s,n,i+1);
        
        // now consider the double digit
         
        if(i+1<n)
        {
            if(s[i]=='1')
                val+=findans(s,n,i+2);
            else if(s[i]=='2' && (s[i+1]>='0' && s[i+1]<='6'))
                val+=findans(s,n,i+2);
        }
        
        return dp[i]=val;
    }
    int numDecodings(string s) {
        int n=s.size();
        memset(dp,-1,sizeof(dp));
        
        return findans(s,n,0);
    }
};