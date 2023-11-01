class Solution {
public:
    int dp[105][105];
    int findans(vector<int>&v,int l,int r){
        if(l+1==r)
            return 0;
        if(dp[l][r]!=-1)
            return dp[l][r];
        
        int ans=INT_MAX;
        for(int k=l+1;k<r;k++){
            ans=min(ans,findans(v,l,k)+findans(v,k,r));
        }
        return dp[l][r]=ans+v[r]-v[l];
        
    }
    int minCost(int n, vector<int>& v) {
        v.push_back(0);
        v.push_back(n);
        sort(v.begin(),v.end());
        memset(dp,-1,sizeof(dp));
        return findans(v,0,v.size()-1);
    }
};