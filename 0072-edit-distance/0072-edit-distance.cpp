class Solution {
public:
    int dp[500][500];
    int findans(string &s,string & t,int i,int j)
    {
        if(j==t.size())
        {
            return s.size()-i;
        }
        else if(i==s.size())
        {
            return t.size()-j;
        }
        
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        int temp=INT_MAX;
        if(s[i]==t[j])
        {
            temp=min(temp,findans(s,t,i+1,j+1));
        }
        else
        {
            temp=min(temp,1+findans(s,t,i,j+1));
            temp=min(temp,1+findans(s,t,i+1,j));
            temp=min(temp,1+findans(s,t,i+1,j+1));
        }
        return dp[i][j]=temp;
    }
    int minDistance(string s, string t) {
        memset(dp,-1,sizeof(dp));
        return findans(s,t,0,0);
    }
};