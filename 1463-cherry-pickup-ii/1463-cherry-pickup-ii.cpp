class Solution {
public:
    int dp[71][71][71];
    int findans(vector<vector<int>>&v,int n,int m,int row,int first,int second)
    {
        if(  first<0 || first>=m || second<0|| second>=m || first>=second)
            return 0;
        if(row==n-1)
            return v[row][first]+v[row][second];
         if(dp[row][first][second]!=-1)
            return dp[row][first][second];
        
        int ans=v[row][first]+v[row][second];
        int val=0;
        for(int i=-1;i<2;i++)
        {
            for(int j=-1;j<2;j++)
            {
                val=max(val,findans(v,n,m,row+1,first+i,second+j));
            }
        }
        return dp[row][first][second]=ans+val;
    }
    int cherryPickup(vector<vector<int>>& v) {
     memset(dp,-1,sizeof(dp));
        int n=v.size();
        int m=v[0].size();
        return findans(v,n,m,0,0,m-1);
    }
};