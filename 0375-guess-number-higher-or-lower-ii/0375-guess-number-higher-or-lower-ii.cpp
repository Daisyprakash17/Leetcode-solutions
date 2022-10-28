class Solution {
public:
    int dp[201][201];
    int findans(int i,int j)
    {
        if(i==j)
            return 0;
        if(i+1==j)
            return i;
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        int val=INT_MAX;
        for(int k=i+1;k<j;k++)
        {
            val=min(val,k+max(findans(i,k-1),findans(k+1,j)));
        }
        
        return dp[i][j]=val;
    }
    int getMoneyAmount(int n) {
        memset(dp,-1,sizeof(dp));
        return findans(1,n);
    }
};