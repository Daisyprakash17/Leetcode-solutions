class Solution {
public:
    vector<string>vs; 
        string temp="123";
    void fillvs(string s,int i,char last,int n)
    {
        if(i>=n)
        {
            vs.push_back(s);
            return ;
        }
        for(int j=0;j<3;j++)
            
            if(last=='#' ||last!= temp[j])
                fillvs(s+temp[j],i+1,temp[j],n);
    }
    int dp[1001][50];
    int mod=1e9+7;
    int findans(int i,int last,int n)
    {
        if(i>=n)
            return 1;
        if(dp[i][last]!=-1)
            return dp[i][last];
        
        int val=0;
        for(int j=0;j<vs.size();j++)
        {
            int flag=1;
            for(int k=0;k<vs[0].size();k++)
                if(vs[last][k]==vs[j][k])
                {
                    flag=0;
                    break;
                }
            if(flag==1)
                val=(val+findans(i+1,j,n))%mod;
        }
        return dp[i][last]=val;
    }
    int colorTheGrid(int n, int m) {
        fillvs("",0,'#',n);
        memset(dp,-1,sizeof(dp));
        
        int res=0;
        for(int i=0;i<vs.size();i++)
        {
            res=(res+findans(1,i,m))%mod;
        }
        return res;
    }
    
};