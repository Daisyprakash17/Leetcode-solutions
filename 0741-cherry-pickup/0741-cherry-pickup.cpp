class Solution {
public:
    int dp[50][50][50][50];
    int findans(int i,int j,int a,int b,vector<vector<int>>&v)
    {
        if(i>=v.size() || a>=v.size())
            return INT_MIN; // this means we not have to consider this value
        if(j>=v[0].size() || b>=v[0].size())
            return INT_MIN; // cannot consider this value as well
        
        if(v[i][j]==-1 || v[a][b]==-1)
            return INT_MIN;
        
          if(a==v.size()-1 && i==v.size()-1 && j==v[0].size()-1 && b==v[0].size()-1)
            return v[a][b];
        
        if(dp[i][j][a][b]!=-1)
            return dp[i][j][a][b];
       
        int aa=findans(i+1,j,a+1,b,v); 
        int bb=findans(i+1,j,a,b+1,v); 
        int c=findans(i,j+1,a+1,b,v); 
        int d=findans(i,j+1,a,b+1,v);
       int  ans=max({aa,bb,c,d});
        
        // if this positions of both robot is not possible 
        // means it is retunring INT_MIN so should return INT_MIN
        // so that previous call can understand that this call is not possible
        if(ans==INT_MIN)
            return dp[i][j][a][b]=ans; // this means that answer is not possible for 
        // this possionts of the robotosw 
        // else we will retunr tghe and 
        int cherry=0;
        cherry+=v[i][j]+v[a][b];
        if(i==a && j==b)
            cherry-=v[i][j];
        return dp[i][j][a][b]=cherry+ans;
        
    }
    int cherryPickup(vector<vector<int>>& v) {
        memset(dp,-1,sizeof(dp));
        int n=v.size();
        int m=v[0].size();
       int ans= findans(0,0,0,0,v);  
        if(ans==INT_MIN)
            ans=0;
        return ans;
        
    }
};