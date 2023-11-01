class Solution {
public:
    int dp[505][505];
    int findans(vector<int>&a,vector<int>&b,int i,int j){
        if(i==a.size() || j==b.size())
            return 0;
        
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        int ans=a[i]*b[j]+findans(a,b,i+1,j+1);
        
        ans=max(ans,findans(a,b,i,j+1));
        ans=max(ans,findans(a,b,i+1,j));
        return dp[i][j]=ans;
        
    }
    int maxDotProduct(vector<int>& a, vector<int>& b) {
        memset(dp,-1,sizeof(dp));
        int res =findans(a,b,0,0);
        if(res>0)
            return res;
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        return max(a[0]*b[b.size()-1],b[0]*a[a.size()-1]);
    }
};