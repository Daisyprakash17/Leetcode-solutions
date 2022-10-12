class Solution {
public:
    int dp[101][101];
    int check(int i,int j,string &s)
    {
        int count=0;
        while(i<=j)
        {
            if(s[i]!=s[j])
                count++;
            i++;
            j--;
        }
        return count;
    }
    int findans(string &s,int i,int k)
    {
        if(i>=s.size())
            return 0;
        
        if(dp[i][k]!=-1)
            return dp[i][k];
        int ans=INT_MAX;
        if(k==1)
            ans=check(i,s.size()-1,s)+findans(s,s.size(),0);
        else
        for(int j=i;j<s.size()-(k-1);j++)
        {
            int count=check(i,j,s);
            ans=min(ans,count+findans(s,j+1,k-1));
        }
        return dp[i][k]=ans;
        
    }
    int palindromePartition(string s, int k) { 
        memset(dp,-1,sizeof(dp));
        
        return findans(s,0,k);
    }
};