class Solution {
public:
    int dp[103][103];
    
    int findans(vector<int>&v,int i,int j)
    {
        // this is if there is no cut remains
        if(i+1>=j)
            return 0;
        
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        int val=INT_MAX;
        
        for(int k=i+1;k<j;k++)
        {
            val=min(val,v[j]-v[i]+findans(v,i,k)+findans(v,k,j));
        }
        return dp[i][j]=val;
        
    }
    int minCost(int n, vector<int>& cuts) {
        memset(dp,-1,sizeof(dp));
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(),cuts.end());
        
        return findans(cuts,0,cuts.size()-1);
    }
};