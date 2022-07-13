class Solution {
public:
    int dp[10002][102];
    
    int findans(int n,int no)
    {
        if(n<=0)
            return 0;
        if(no<=0)
            return INT_MAX-2;
        
        if(dp[n][no]!=-1)
            return dp[n][no];
        int val=INT_MAX;
        if(no*no<=n)
        {
             val=1+min(findans(n-no*no,no),findans(n-no*no,no-1));
            
        } 
            return dp[n][no]=min(val,findans(n,no-1));
    }
    int numSquares(int n) {
        memset(dp,-1,sizeof(dp)); 
        return findans(n,100);
        
    }
};