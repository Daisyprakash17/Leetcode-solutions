class Solution {
public:
    int dp[1001][1001];
    int final_ans=INT_MIN;
    int findans(vector<vector<int>>&v,int i,int j){
        
        if(i==v.size()-1 && j==v[0].size()-1)
            return 0;
        if(dp[i][j]!=INT_MIN){
            return dp[i][j];
        }
        int ans=INT_MIN;
            if(j+1<v[0].size())
            ans=max(ans,max(v[i][j+1]-v[i][j],v[i][j+1]-v[i][j]+findans(v,i,j+1)));
            if(i+1<v.size())
            ans=max(ans,max(v[i+1][j]-v[i][j],v[i+1][j]-v[i][j]+findans(v,i+1,j)));
        final_ans=max(final_ans,ans);
        return dp[i][j]=ans;
    }
    int maxScore(vector<vector<int>>& v) {
      
        for(int i=0;i<1001;i++){
            for(int j=0;j<1001;j++)
                dp[i][j]=INT_MIN;
        }
        findans(v,0,0);
        return final_ans;
    }
};