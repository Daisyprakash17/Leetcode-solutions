class Solution {
public:
    int dp[1000][2][2];
    int findans(vector<int>&v,int i,int val,int pre)
    { 
        if(i==v.size()-1)
        {
            if(val==0)
                return 1;
            else 
                return 0;
        }
            if(dp[i][val][pre]!=-1)
                return dp[i][val][pre];
            
            int temp=0;
            if(pre==1 && val==0)
                temp=1;
            for(int j=i+1;j<v.size();j++)
            {
                if(v[j]>v[i])
                {
                    if(val==1)
                    temp=max(temp,1+findans(v,j,1,1));
                }
                else if(v[j]<v[i])
                {
                    if(pre==1)
                    temp=max(temp,1+findans(v,j,0,1));
                }
            }
            return dp[i][val][pre]=temp;
        
    }
    int minimumMountainRemovals(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        
        int temp=0;
        for(int i=0;i<nums.size();i++)
       temp=max(temp,findans(nums,i,1,0));
       return  nums.size()-temp;
    }
};