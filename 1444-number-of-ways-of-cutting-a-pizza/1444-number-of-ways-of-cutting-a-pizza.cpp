class Solution {
public:
    int dp[51][51][11];
    int mod=1e9+7;
    int findans(vector<string>&v,int i,int j,int n,int m,int k)
    { 
        if(k==0)
        { 
            for(int r=i;r<n;r++)
                for(int c=j;c<m;c++) 
                    if(v[r][c]=='A')
                    return 1;
            return 0;
                 
        }
        if(i==n-1 && j==m-1 && k>0)
            return 0; // if we still have to make pieces but we cannot make more pieces
        
        if(dp[i][j][k]!=-1)
            return dp[i][j][k];
        
        int val=0;
        
        int flag=0;
        // horizontal cuts
        for(int r=i;r<n-1;r++)
        {
            if(flag==0){
            for(int c=j;c<m;c++)
                if(v[r][c]=='A')
                    flag=1;}
            
            if(flag==1)
               {
                 val=(val+findans(v,r+1,j,n,m,k-1))%mod;
            }
        }
        
        // vertival cuts
        flag=0;
        for(int c=j;c<m-1;c++)
        {
            if(flag==0)
            {
                for(int r=i;r<n;r++)
                {
                    if(v[r][c]=='A')
                        flag=1;
                }
            }
            if(flag==1)
            {
                 val=(val+findans(v,i,c+1,n,m,k-1))%mod;
            }
        }
        
        return dp[i][j][k]=val;
        
    }
    int ways(vector<string>& v, int k) {
        memset(dp,-1,sizeof(dp));
        int n=v.size();
        int m=v[0].size();
        
        return findans(v,0,0,n,m,k-1);
    }
};