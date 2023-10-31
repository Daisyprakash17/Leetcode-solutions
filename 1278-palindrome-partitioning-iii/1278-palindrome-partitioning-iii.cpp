class Solution {
public:
    int dp[101][101];
    int getval(string & s,int i,int j){
        int count =0;
        while(i<=j)
        {
            if(s[i++]!=s[j--])
                count++;
        }
        return count;
    }
    int findans(string &s,int i,int k){
        
        
        if(dp[i][k]!=-1)
            return dp[i][k];
        int ans=1e5;
        if(k==1)
            ans=getval(s,i,s.size()-1);
        else
        for(int j=i;j<=s.size()-k;j++){
            ans=min(ans,getval(s,i,j)+findans(s,j+1,k-1));
        }
        return dp[i][k]=ans;
        
        
    }
    int palindromePartition(string s, int k) {
        memset(dp,-1,sizeof(dp));
        return findans(s,0,k);
    }
};