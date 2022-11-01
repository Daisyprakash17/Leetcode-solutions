class Solution {
public:
    int dp[301][11];
    int findans(vector<int>&v,int i,int n,int d)
    {
        if(i==n)
            return 0;
        if(d==0)
            return -1;
        if(dp[i][d]!=-1)
            return dp[i][d];
        
        int ans=INT_MAX;
        int cur=-1;
        
        for(int j=i;j<=n-d;j++)
        {
            cur=max(cur,v[j]);  
            int curval=findans(v,j+1,n,d-1);
            if(curval!=-1)
            ans=min(ans,curval+cur);
        }
        return dp[i][d]=ans;
    }
    int minDifficulty(vector<int>& v, int d) {
        int n=v.size();
        if(n<d)
            return -1;
        memset(dp,-1,sizeof(dp));
        return findans(v,0,n,d);
    }
};