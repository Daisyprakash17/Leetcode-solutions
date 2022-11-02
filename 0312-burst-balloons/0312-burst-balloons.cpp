class Solution {
public:
    int dp[302][302];
    
    int findans(vector<int>&v,int i,int j)
    {
        if(i>=j)
            return 0; 
        
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        
        int ans=-1;
        
        for(int k=i;k<j;k++)
        {
            int temp=findans(v,i,k)+findans(v,k+1,j);
            temp+=v[i-1]*v[k]*v[j];
            ans=max(ans,temp);
        }
        return dp[i][j]=ans;
        
    }
    int maxCoins(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        nums.insert(nums.begin(),1);
        nums.push_back(1);
        return findans(nums,1,nums.size()-1);
    }
};