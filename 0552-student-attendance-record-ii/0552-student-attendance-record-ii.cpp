class Solution {
public:
        int dp[100005][2][3];
        int mod=1e9+7;
        int findans(int i,int n,int a,int l){
            if(i>=n)
                return 1;
            if(dp[i][a][l]!=-1)
                return dp[i][a][l];
            
            int ans=0;
            // if marking the student as prennt
            ans=(ans+findans(i+1,n,a,0))%mod;
            
            // if marking the student as late 
            // that only possible if not late for 2 consecutive days
            if(l<2)
                ans=(ans+findans(i+1,n,a,l+1))%mod;
            
            // if want to make the currnet studetn as abent 
            // then this is only possible if the student have not taken a leave already
            
            if(a==1)
                ans=(ans+findans(i+1,n,0,0))%mod;
            return dp[i][a][l]=ans;
        }
    int checkRecord(int n) {
        memset(dp,-1,sizeof(dp));
        return findans(0,n,1,0);
    }
};