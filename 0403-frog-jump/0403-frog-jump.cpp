class Solution {
public:
    int dp[2001][2001];
    map<int,int>m;
    
    bool findans(vector<int>&v,int n,int jump)
    {
        if(n==1)
            return true;
        if(dp[n][jump]!=-1)
            return dp[n][jump];
         
       
        if(m[v[n-1]+jump+1]>0)
        {
            if(findans(v,m[v[n-1]+jump+1],jump+1))
                return dp[n][jump]=true;
            
        }
         if(m[v[n-1]+jump]>0)
        {
            if(findans(v,m[v[n-1]+jump],jump))
                return dp[n][jump]=true;
            
        }
        if(m[v[n-1]+jump-1]>0 && jump>1)
        {
            if(findans(v,m[v[n-1]+jump-1],jump-1))
                return dp[n][jump]=true;
            
        }
        return dp[n][jump]=false;
    }
    bool canCross(vector<int>& stones) {
        int n=stones.size();
        if(stones[1]!=1)
            return false;
        memset(dp,-1,sizeof(dp));
        reverse(stones.begin(),stones.end());
        
        for(int i=0;i<n;i++)
            m[stones[i]]=i+1;
        return findans(stones,n-1,1);
    }
};