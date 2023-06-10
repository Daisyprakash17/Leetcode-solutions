class Solution {
public:
    vector<int>pos;
    int dp[100000];
    int mod=1e9+7;
    int findans(string &s,int i,int n)
    {
        if(i>=n-1)
            return 1;
        if(dp[i]!=-1)
            return dp[i];
        auto first=lower_bound(pos.begin(),pos.end(),i);
         
        auto second=lower_bound(pos.begin(),pos.end(),(*first)+1);
         if(pos[pos.size()-1]==*second)
             return dp[i]=1;
        
        auto third=lower_bound(pos.begin(),pos.end(),(*second)+1);
        long long diff=(*third)-(*second);
         long long val=(diff*findans(s,*third,n))%mod;
        return dp[i]=val;
    }
    int numberOfWays(string s) {
            for(int i=0;i<s.size();i++)
            {
                if(s[i]=='S')
                    pos.push_back(i);
            }
        if(pos.size()%2==1  || pos.size()==0)
            return 0;
        
      memset(dp,-1,sizeof(dp));
        
        return findans(s,0,s.size());
    }
};