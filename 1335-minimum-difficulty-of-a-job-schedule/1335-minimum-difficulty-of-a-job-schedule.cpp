class Solution {
public:
    int dp[301][11];
    int findans(vector<int>&v,int i,int d){
        if(i>=v.size())
        {
            return d==0?0:1e7;
        }
        if(d==0)
            return i>=v.size()?0:1e7;
        
        if(dp[i][d]!=-1)
            return dp[i][d];
        int temp=1e7;
        int cur=v[i];
        for(int j=i;j<v.size();j++){
            cur=max(cur,v[j]);
            temp=min(temp,cur+findans(v,j+1,d-1));
        }
        return dp[i][d]=temp;
    }
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        memset(dp,-1,sizeof(dp));
     int ans=findans(jobDifficulty,0,d);
            if(ans==1e7)
                return -1;
        return ans;
    }
};