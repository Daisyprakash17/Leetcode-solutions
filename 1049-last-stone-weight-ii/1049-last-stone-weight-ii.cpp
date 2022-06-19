class Solution {
public:
    int dp[31][3001];
    
    int findans(vector<int>&v,int sum,int n)
    {
        if(sum==0)
            return 1;
        if(n==0)
            return 0;
        if(dp[n][sum]!=-1)
            return dp[n][sum];
        if(v[n-1]<=sum)
          return   dp[n][sum]=findans(v,sum-v[n-1],n-1)|findans(v,sum,n-1);
        else
           return  dp[n][sum]=findans(v,sum,n-1);
    }
    int lastStoneWeightII(vector<int>& v) {

        memset(dp,-1,sizeof(dp));
        int sum=0;
        for(auto i:v)
            sum+=i;
        findans(v,sum,v.size());
        int n=v.size();
        
         int mi=INT_MAX;
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=sum;j++) 
            { 
                if(dp[i][j]!=-1)
                {
                    mi=min(mi,abs(sum-2*j));
                } 
            } 
        } 
        return mi;
        
    }
};