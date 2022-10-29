class Solution {
public:
    int dp[5001][7];
    int mod=1e9+7;
    // l means the elemnt that we should not consider
    int findans(vector<int>&v,int n,int l)
    {
        if(n<=0)
            return 1;
        
        if(l!=0 && dp[n][l]!=-1)
            return dp[n][l];
        
        int val=0;
        
        for(int i=1;i<=6;i++)
        {
            if(l==i)
                continue;
            
            for(int k=1;k<=v[i];k++)
            {
                if(n-k>=0)
                val=(val+findans(v,n-k,i))%mod;
            }
        }
        if(l==0)
            return val;
        return dp[n][l]=val;
    }
    int dieSimulator(int n, vector<int>& v) {
        memset(dp,-1,sizeof(dp));
        
        reverse(v.begin(),v.end());
        v.push_back(0);
        reverse(v.begin(),v.end());
        return findans(v,n,0);
    }
};