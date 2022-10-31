class Solution {
public:
    int mod=1e9+7;
    int dp[10001][7][7];
    int findans(int in,int n,int first,int second )
    {
        if(in>n)
            return 1;
        
        if(  dp[in][first][second]!=-1)
            return dp[in][first][second];
    long long  val=0;
        for(int i=1;i<7;i++)
        {
            if(i!=first && i!=second &&(second==0  || (__gcd(second,i)==1)) )
            {
                 val=(val+findans(in+1,n,second,i))%mod;
            }
        } 
        return dp[in][first][second]=val;
    }
    int distinctSequences(int n) { 
        memset(dp,-1,sizeof(dp));
       return  findans(1,n,0,0);
        
    }
};