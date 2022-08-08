class Solution {
public:
    int dp[100001][2];
    int findans(int n,int who)
    {
        if(n==0)
        {
            if(who==0)
                return 1; // alice won
            else
                return 0; // bob won
        }
        if(dp[n][who]!=-1)
            return dp[n][who];
        int ans=0;
        if(who==0)
            ans=1;
        for(int i=1;i<=sqrt(n);i++)
        {
            
            if(who==1)
            {
                int val=findans(n-i*i,0);
                if(val==1)
                   {
                    ans=1;
                   break;
                   }
            }
            else
            {
                int val=findans(n-i*i,1);
                if(val==0)
                     {
                    ans=0;
                   break;
                }
            }
        }
        return dp[n][who]=ans;
        
        
    }
    bool winnerSquareGame(int n) {
        memset(dp,-1,sizeof(dp));
        return findans(n,1);
    }
};