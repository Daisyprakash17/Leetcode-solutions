class Solution {
public:
    int dp[50001][2];
    int findans(vector<int>&v,int i,int who)
    {
            if(i>=v.size())
                return 0;
        if(dp[i][who]!=-1)
            return dp[i][who];
        int ans=INT_MIN;
        if(who==0)
            ans=INT_MAX;
        
        int sum=0; 
        int count=0;
        for(int j=i;j<v.size() && count<3;j++)
        {
            count++;
            sum+=v[j];
            if(who==1)
                ans=max(ans,sum+findans(v,j+1,0));
            else
                ans=min(ans,-sum+findans(v,j+1,1));
        }
        return dp[i][who]=ans;
    }
    string stoneGameIII(vector<int>& stoneValue) {
    memset(dp,-1,sizeof(dp));
        int val=findans(stoneValue,0,1);
        if(val>0)
            return "Alice";
        else if(val<0)
            return "Bob";
        else
            return "Tie";
    }
};