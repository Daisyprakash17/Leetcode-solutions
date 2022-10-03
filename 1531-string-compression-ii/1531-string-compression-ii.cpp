class Solution {
public:
    char dp[101][101][27][101];
    int findans(string & s,int n,int k,int last,int lastcount)
    {
        if(n<0)
            return 0;    
        if(dp[char(n)][char(k)][char(last)][char(lastcount)]!=-1)
            return dp[char(n)][char(k)][char(last)][char(lastcount)];
        int val=INT_MAX; 
        int curval=s[n]-'a'; 
        if(last==curval || last==26)
        {
            // if last char taken is equal to cur character
            
            if(last==26)
                val=1+findans(s,n-1,k,curval,1);
            else
            {
            int cur=0;
            if(lastcount==1 || lastcount==9 || lastcount==99)
                cur=1; 
            val= cur+findans(s,n-1,k,last ,lastcount+1);
            } 
        }
        else
            {
            val=1+findans(s,n-1,k,curval,1);
        }
        if(k>0)
           val=min(val,findans(s,n-1,k-1,last,lastcount)); 
        return dp[char(n)][char(k)][char(last)][char(lastcount)]=val;
    }
    int getLengthOfOptimalCompression(string s, int k) {
        memset(dp,-1,sizeof(dp));
        return findans(s,s.size()-1,k,26,0);
    }
};