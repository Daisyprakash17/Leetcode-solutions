class Solution {
public:
    int dp[100005][2][3];
    int mod=1e9+7;
    int findans(int n ,int i,int a,int l){
        
        if(i>=n)
            return 1;
        if(dp[i][a][l]!=-1)
            return dp[i][a][l];
        // this is where student was present
        int ans=findans(n,i+1,a,2);
        
        // if student was absent
        if(a==1){
            ans=(ans+findans(n,i+1,0,2))%mod;
        }
        
        // if student was late
        if(l>0){
            ans=(ans+findans(n,i+1,a,l-1))%mod;
        }
        return dp[i][a][l]=ans;
        
    }
    int checkRecord(int n) {
        memset(dp,-1,sizeof(dp));
        return findans(n,0,1,2);
    }
};