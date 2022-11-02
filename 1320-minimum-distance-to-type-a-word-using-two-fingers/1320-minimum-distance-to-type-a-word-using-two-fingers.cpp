class Solution {
public:
    int dp[301][27][27];
    int dis(char c,int i)
    {
        if(i==-1)
            return 0;
        int val=c-'A';
        return (abs((i%6)-(val%6))+abs((i/6)-(val/6)));
        
    }
    int findans(string &s,int i,int f,int se)
    {
        if(i==s.size())
            return 0;
        if(f!=-1 && se!=-1 && dp[i][f][se]!=-1)
            return dp[i][f][se];
        
        int val=INT_MAX;
        int pos=s[i]-'A';
        // if using first finger
        val=min(val,dis(s[i],f)+findans(s,i+1,pos,se));
        
        // if using  second finger
        val=min(val,dis(s[i],se)+findans(s,i+1,f,pos));
        if(f==-1 || se==-1)
            return val;
        return dp[i][f][se]=val;
        
    }
    int minimumDistance(string word) {
        memset(dp,-1,sizeof(dp));
        return findans(word,0,-1,-1);
    }
};