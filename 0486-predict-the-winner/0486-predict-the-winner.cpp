class Solution {
public:
    int dp[21][21][2];
    int findans(vector<int>&v,int i,int j,int who)
    {
        if(i>j)
            return 0;
        if(dp[i][j][who]!=-1)
            return dp[i][j][who];
        
        int res;
        if(who==1)
        {
            // if this is the turn of the second person
            
         res=min(-v[i]+findans(v,i+1,j,0),-v[j]+findans(v,i,j-1,0)); 
                 
        }
        else
        {
            res=max(v[i]+findans(v,i+1,j,1),v[j]+findans(v,i,j-1,1));
        }
        return dp[i][j][who]=res;
    }
    bool PredictTheWinner(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        int n=nums.size();
        return findans(nums,0,n-1,0)>=0;
    }
};