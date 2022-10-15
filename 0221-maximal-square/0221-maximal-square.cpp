class Solution {
public:
    int dp[301][301];
    
    int findans(int i,int j,vector<vector<char>>&v)
    {
            if(i>=v.size() || i<0 || j>=v[0].size() || j<0 || v[i][j]=='0')
                return 0;
        
        
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        int left=findans(i,j+1,v);
        int right=findans(i+1,j,v);
        int dia=findans(i+1,j+1,v);
        
        return dp[i][j]=1+min(left,min(right,dia));
    }
    int maximalSquare(vector<vector<char>>& v) {
        memset(dp,-1,sizeof(dp));
        
        int ans=0;
         
        
        for(int i=0;i<v.size();i++)
        {
            
            for(int j=0;j<v[0].size();j++)
            {
                
                if(v[i][j]=='1')
                {
                    int len=findans(i,j,v);
                    ans=max(ans,len*len);
                }
            }
        }
        return ans;
    }
};