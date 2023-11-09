class Solution {
public:
    int dp[105][105];
    static bool cmp(vector<int>&a,vector<int>&b){
        if(a[0]==b[0]){
            if(a[1]==b[1]){
                
                return a[2]<b[2];
            }
            else{
                return a[1]<b[1];
            }
        }
        else
            return a[0]<b[0];
    }
    int findans(vector<vector<int>>&v,int i,int j){
        
        if(j==v.size())
            return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        int ans=0;
        
        if(v[j][0]>=v[i][0] && v[j][1]>=v[i][1] && v[j][2]>=v[i][2]){
            // here i have the option to either select block or not 
            ans=max(v[j][2]+findans(v,j,j+1),findans(v,i,j+1));
        }
        else{
            // here have no option of selecting 
            ans=findans(v,i,j+1);
        }
        return dp[i][j]=ans;
    }
    int maxHeight(vector<vector<int>>& v) {
        memset(dp,-1,sizeof(dp));
        v.push_back({0,0,0});
        for(int i=0;i<v.size();i++)
        {
            sort(v[i].begin(),v[i].end());
        }
        sort(v.begin(),v.end(),cmp);
        
        
        
        return findans(v,0,1);
    }
};