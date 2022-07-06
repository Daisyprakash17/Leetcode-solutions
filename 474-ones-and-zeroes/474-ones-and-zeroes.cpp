class Solution {
public:
    int dp[101][101][601];
    int findans(vector<pair<int,int>>&v,int z,int o,int n)
    {
        if(z<0 || o<0 || (z==0 && o==0)  || n==0)
            return 0;
        if(dp[z][o][n]!=-1)
            return dp[z][o][n];
        
        if(v[n-1].first<=z && v[n-1].second<=o)
        {
            return dp[z][o][n]=max(1+findans(v,z-v[n-1].first,o-v[n-1].second,n-1),
                                  findans(v,z,o,n-1));
        }
        else
        {
            return dp[z][o][n]=findans(v,z,o,n-1);
        }
    }
    int findMaxForm(vector<string>& strs, int z, int o) {
        vector<pair<int,int>>v;
        for(auto s:strs)
        {
            int first=count(s.begin(),s.end(),'0'); 
            int second=count(s.begin(),s.end(),'1');
            v.push_back({first,second});
        }
        memset(dp,-1,sizeof(dp));
        
        return findans(v,z,o,v.size());
    }
};