class Solution {
public:
    int dp[2000];
    bool check(string &s,int i,int j){
        while(i<=j)
            if(s[i++]!=s[j--])
                return false;
        return true;
    }
    int findans(string & s,int i){
        if(i>=s.size())
            return 0;
        if(dp[i]!=-1)
            return dp[i];
        int ans=INT_MAX;
        for(int j=i;j<s.size();j++){
                if(check(s,i,j)){
                    ans=min(ans,1+findans(s,j+1));
                        
                }
        }
        return dp[i]=ans;
        
    }
    int minCut(string s) {
        memset(dp,-1,sizeof(dp));
        return findans(s,0)-1;
    }
};