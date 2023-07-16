class Solution {
public:
    int dp[50];
    int findans(int i)
    {
        if(i<0)
            return 0;
        if(i==0)
            return 1; 
        if(dp[i]!=-1)
            return dp[i];
        
        return dp[i]=findans(i-1)+findans(i-2);
    }
    int climbStairs(int n) {
        memset(dp,-1,sizeof(dp));
        
        return findans(n);
    }
};