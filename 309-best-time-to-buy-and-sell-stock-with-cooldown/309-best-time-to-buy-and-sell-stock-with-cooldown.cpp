class Solution {
public:
    int dp[5002][2];
    int findans(vector<int>&v,int s,int n)
    {
        if(n<=0)
            return 0;
        
        if(dp[n][s]!=-1)
            return dp[n][s];
        int first,second;
        if(s==0)
        {
            // if we do not have the stock 
            first=-v[n-1]+findans(v,1,n-1);
            second=0+findans(v,0,n-1);
        }
        else
        {
            // if we have the stock 
            first=v[n-1]+findans(v,0,n-2);
            second=0+findans(v,1,n-1);
        }
        return dp[n][s]=max(first,second);
        }
    int maxProfit(vector<int>& v) {
        memset(dp,-1,sizeof(dp));
        reverse(v.begin(),v.end());
        int sum=0;
        return findans(v,0,v.size());
    }
};