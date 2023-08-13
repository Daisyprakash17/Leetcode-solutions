class Solution {
public:
    int dp[1000][1000];
    int findans(string &a,string &b,int i,int j)
    {
        if(i==a.size() || j==b.size())
            return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        int val=0;
        if(a[i]==b[j])
        {
            val=max(val,1+findans(a,b,i+1,j+1));
        }
        else
        {
        val=max(val,findans(a,b,i+1,j));
        val=max(val,findans(a,b,i,j+1));
        }
        return dp[i][j]=val;
    }
    
    int minDistance(string word1, string word2) {
        memset(dp,-1,sizeof(dp));
        int ans=findans(word1,word2,0,0);
        return word1.size()+word2.size()-2*ans;
    }
};