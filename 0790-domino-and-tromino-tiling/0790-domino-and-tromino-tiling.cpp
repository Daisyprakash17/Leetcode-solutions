class Solution {
public:
    int dp[1001][2][2];
    int mod=1000000007;
    int findans(int i,int first,int second,int n)
    {
        if(i>n  )
        {
             return 0;
        }
        if(i==n)
        {
            if(first==0 && second==0)
                return 1;
            else
                return 0;
            
        }
        if(dp[i][first][second]!=-1)
            return dp[i][first][second];
        int val=0;
        
        if(first==0 && second==0)
        {
            val=(val+findans(i+1,0,0,n))%mod;
            val=(val+findans(i+1,0,1,n))%mod;
            val=(val+findans(i+1,1,0,n))%mod;
            val=(val+findans(i+2,0,0,n))%mod;
        }
        else
        {
            if(first==1 && second==0)
            {
                val=(val+findans(i+1,0,1,n))%mod;
                val=(val+findans(i+2,0,0,n))%mod;
            }
            else 
            {
                val=(val+findans(i+2,0,0,n))%mod;
                val=(val+findans(i+1,1,0,n))%mod;
            }
        }
        return dp[i][first][second]=val;
    }

    int numTilings(int n) {
        memset(dp,-1,sizeof(dp));
        return findans(0,0,0,n);
    }
};