class Solution {
public:
    int dp[71][71][71];
    int findans(int row,int i,int j,vector<vector<int>>&v)
    {
        
        if(row>=v.size())
            return 0;
        if(i<0 || j<0 || i>=v[0].size() || j>=v[0].size())
            return -1;
        if(dp[row][i][j]!=-1)
            return dp[row][i][j];
        
        int val=0;
        
        for(int a=-1;a<=1;a++)
            for(int b=-1;b<=1;b++)
            {
                int temp=findans(row+1,i+a,j+b,v); 
                if(temp!=-1)
                    val=max(val,temp);
            }
        
        
            val+=v[row][i]+v[row][j];
        if(i==j)
            val-=v[row][i];
        
        return dp[row][i][j]=val;
    }
    int cherryPickup(vector<vector<int>>& v) {
        memset(dp,-1,sizeof(dp));
        int n=v.size();
        int m=v[0].size();
        return findans(0,0,m-1,v);
    }
};