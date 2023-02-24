class Solution {
public:
    int dp[1001][2001];
    int findans(int i,int n,vector<vector<int>>&v,int k)
    {
        if(i==n)
        {
            if(k==0)
                return 0;
            else
                return INT_MIN;
        }
        else if(k==0)
            return 0;
        if(dp[i][k]!=-1)
            return dp[i][k];
        int temp=INT_MIN;
        int cur=k;
        int sum=0;
        temp=max(temp,findans(i+1,n,v,k));
        for(auto j:v[i])
        {
            
            if(k==0)
                break;
            sum+=j;
            k--;
                temp=max(temp,sum+findans(i+1,n,v,k));
            
        }
        return dp[i][cur]=temp;
    }
    
    int maxValueOfCoins(vector<vector<int>>& v, int k) {
        int n=v.size();
         memset(dp,-1,sizeof(dp));
        
        return findans(0,n,v,k);
        
        
    }
};