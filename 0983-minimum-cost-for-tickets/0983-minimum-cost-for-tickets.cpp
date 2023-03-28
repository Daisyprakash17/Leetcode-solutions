class Solution {
public:
    int findans(vector<int>&d,vector<int>&c,vector<int>&dp,int in)
    {
        if(in==d.size())
            return 0; // if we have ready to n days 
        if(dp[in]!=-1)
            return dp[in];
        
        int sum=0;
        int val=d[in];
        
        sum=c[0]+findans(d,c ,dp,in+1);
        auto it=lower_bound(d.begin(),d.end(),val+7);
        sum=min(sum,c[1]+findans(d,c,dp,(it-d.begin())));
        
         it=lower_bound(d.begin(),d.end(),val+30);
        sum=min(sum,c[2]+findans(d,c,dp,(it-d.begin())));
        
        return dp[in]=sum;
        
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int d=days.size();
        vector<int>dp(d,-1);
        
        return findans(days,costs,dp,0);
    }
};