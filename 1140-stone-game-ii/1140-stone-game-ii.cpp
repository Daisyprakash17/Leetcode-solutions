class Solution {
public:
    int dp[101][150][2];
    int findans(vector<int>&v,int i,int m,int who)
    {
        if(i>v.size())
            return 0;
        
        if(dp[i][m][who]!=-1)
            return dp[i][m][who];
        
        int ans=0;
        if(who==0)
            ans=INT_MAX;
        int count=0;
        int sum=0;
        for(int j=i;j<=v.size()  && count<2*m;j++ )
        {
            count++;
            sum+=v[j-1];
            if(who==1)
                ans=max(ans,sum+findans(v,j+1,max(m,count),0));
            else
                ans=min(ans,findans(v,j+1,max(m,count),1));
        }
        return dp[i][m][who]=ans;
    }
    int stoneGameII(vector<int>& piles) {
        memset(dp,-1,sizeof(dp));
        return findans(piles,1,1,1);
    }
};