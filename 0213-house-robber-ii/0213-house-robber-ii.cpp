class Solution {
public:
    int dp[1000][2];
        int findans(vector<int>&v,int i,int t){
            if((t==0 && i>=v.size()-1) || (t==1 && i>=v.size()))
                return 0;
            
            if(dp[i][t]!=-1)
                return dp[i][t];
            
            int ans=max(v[i]+findans(v,i+2,t),findans(v,i+1,t));
            return dp[i][t]=ans;
        }
    int rob(vector<int>& v) {
        memset(dp,-1,sizeof(dp));
        if(v.size()==1)
            return v[0];
        return max(findans(v,0,0),findans(v,1,1));
    }
};