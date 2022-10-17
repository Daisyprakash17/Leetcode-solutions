class Solution {
public:
    double dp[101][101];
    
    double findans(vector<int>&v,int i,int n,int k)
    {
        
        if(k==1)
        {
            double sum=0;
            for(int j=i;j<n;j++)
                sum+=v[j];
            return dp[i][k]=sum/(n-i);
        }
          
        if(to_string(dp[i][k])!="-nan")
            return dp[i][k];
        
         
        double ma=0;
        double sum=0;
        for(int j=i;j<=n-k;j++)
        {
            sum+=v[j]; 
            
            ma=max(ma,(findans(v,j+1,n,k-1)+sum/(j-i+1)));
        } 
        return dp[i][k]=ma;
    }
    double largestSumOfAverages(vector<int>& nums, int k) {
            memset(dp,-1,sizeof(dp));
             return findans(nums,0,nums.size(),k);
    }
};