class Solution {
public:
    int dp[500][500];
    int findans(int i,int k,int n,vector<int>&v)
    {
        if(i>=n || k==0)
            return 0;
        if(dp[i][k]!=-1)
            return dp[i][k];
        int taken=v[i]+findans(i+2,k-1,n,v);
        int nottaken=findans(i+1,k,n,v);
        return dp[i][k]=max(taken,nottaken);
    }
    int maxSizeSlices(vector<int>& v) {
        memset(dp,-1,sizeof(dp));
        int n=v.size();
        int k=n/3;
        int first=v[0]+findans(2,k-1,n-1,v);
        memset(dp,-1,sizeof(dp));
        int second=findans(1,k,n,v);
        return max(first,second);
    }
};