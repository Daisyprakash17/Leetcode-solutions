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
        int ans=0; // is alice turn intially not winning
        if(who==0)
            ans=1; // if bob turn intially not winning
        for(int i=1;i<=sqrt(n);i++)
        {
            
            if(who==1)
            {
                int val=findans(n-i*i,0);
                // in this alice want to win 
                // for it is expecting 1 from the recursise call
                if(val==1)
                   {
                    ans=1;
                   break;
                   }
            }
            else
            {
                int val=findans(n-i*i,1); 
                // in this bob want to win
                // for will bob is expecting 0 from the recursice call
                if(val==0)
                     {
                    ans=0;
                   break;
                }
            }
        }
        // so if ans is 1 alice is winning 
        // and if ans i 0 bob is winning
        return dp[n][who]=ans;
        
        
    }
    bool winnerSquareGame(int n) {
        memset(dp,-1,sizeof(dp));
        return findans(n,1);
    }
};