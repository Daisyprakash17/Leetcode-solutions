class Solution {
public:
    int dp[1001][1001][2];
    
    int findans(vector<int>&v,int i,int j,int who,int sum)
    {
        if(i>j)
            return 0;
        
        if(dp[i][j][who]!=-1)
            return dp[i][j][who];
        int ans=0;
        if(who==0)
            ans=INT_MAX;
        if(who==1)
        {
            ans=max(sum-v[i-1]+findans(v,i+1,j,0,sum-v[i-1]),sum-v[j-1]+findans(v,i,j-1,0,sum-v[j-1]));
        }
        else
        {
            ans=min(-(sum-v[i-1])+findans(v,i+1,j,1,sum-v[i-1]),-(sum-v[j-1])+findans(v,i,j-1,1,sum-v[j-1]));
        }
        return dp[i][j][who]=ans;
    }
    int stoneGameVII(vector<int>& stones) {
        int sum=0;
        for(auto i:stones)
            sum+=i;
        
        memset(dp,-1,sizeof(dp));
        return  findans(stones,1,stones.size(),1,sum);
        
    }
};