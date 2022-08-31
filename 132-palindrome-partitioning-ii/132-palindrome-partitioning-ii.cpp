class Solution {
public:
    int dp[2001]; 
    int findans(string &s,int i)
    {
        
            if(i>=s.size())
                return 0;
        if(dp[i]!=-1)
            return dp[i];
        int ans=INT_MAX;
        for(int j=i;j<s.size();j++)
        {
         int first=i;
            int second=j;
            int flag=1;
            while(first<=second)
            {
                if(s[first]!=s[second])
                {
                    flag=0;
                    break;
                }
                first++;
                second--;
                
            }
            if(flag)
                ans=min(ans,1+findans(s,j+1));
        }
        return dp[i]=ans;
    }
   
    int minCut(string s) {
        memset(dp,-1,sizeof(dp));
        
        return findans(s,0)-1;
    }
};