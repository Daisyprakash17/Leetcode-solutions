class Solution {
public:
    int dp[10][100000];
    int findans(vector<int>&v,int val,int o)
    {
        if(2*o>v.size())
            return 0;
        
        if(dp[o][val]!=-1)
            return dp[o][val];
        int temp=0;
        for(int i=0;i<v.size();i++)
        {
            if((val&(1<<i))!=(1<<i))
            {
                 
                for(int j=i+1;j<v.size();j++)
                {
                    if((val&(1<<j))!=(1<<j))
                    {
                        
                      temp=max(temp,__gcd(v[i],v[j])*o+findans(v,val|(1<<i)|(1<<j),o+1));
                        
                    }
                } 
            }
        }
        return dp[o][val]=temp;
    }
    int maxScore(vector<int>& nums) {
        int val=0;
        int o=1;
        memset(dp,-1,sizeof(dp));
        return findans(nums,val,o);
    }
};