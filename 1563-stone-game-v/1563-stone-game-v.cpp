class Solution {
public:
    int dp[501][501];
    vector<int>val;
    int findans(int i,int j)
    {
        if(i>=j)
            return 0;
        
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        int sum=val[j]-val[i-1]; 
        int ans=0;
        for(int k=i;k<j;k++)
        {
            int cursum=val[k]-val[i-1];
            int resum=sum-cursum;
            if(cursum==resum)
            {
                
                ans=max(ans,cursum+max(findans(i,k),findans(k+1,j)));
            }
            else
            {
                if(cursum<resum)
                {
                    ans=max(ans,cursum+findans(i,k));
                }
                else
                {
                    ans=max(ans,resum+findans(k+1,j));
                }
            }
        }
        return dp[i][j]=ans;
            
            
    }
    int stoneGameV(vector<int>& v) {
        int n=v.size();
        val.push_back(0);
        for(int i=0;i<n;i++)
            val.push_back(val[i]+v[i]);
        
        memset(dp,-1,sizeof(dp));    
        return findans(1,n);
    }
};