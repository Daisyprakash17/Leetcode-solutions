class Solution {
public:
    int dp[501][501][2];
    
    int findans(vector<int>&v,int i,int j,int who)
    {
        if(i>j)
            return 0;
         if(dp[i][j][who]!=-1)
             return dp[i][j][who];
        
        int ans=0;
        if(who==1)
        {
            // this is alice's turn
            // in this alice will try to maxi the current ans
            ans=max(v[i-1]+findans(v,i+1,j,0),v[j-1]+findans(v,i,j-1,0));
        }
        else
        {
            // this is bob turn 
            // in this bob will try to return the least value
            // so that chances of winning of alice will reduce
            ans=min(-v[i-1]+findans(v,i+1,j,1),-v[j-1]+findans(v,i,j-1,1));
        }
        return dp[i][j][who]=ans;
    }
    bool stoneGame(vector<int>& piles) {
        memset(dp,-1,sizeof(dp));
        return findans(piles,1,piles.size(),1)>0;
    }
};