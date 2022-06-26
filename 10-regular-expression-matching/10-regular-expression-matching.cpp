class Solution {
public:
     int findans(string &a,string &p,int n,int m,vector<vector<int>>& dp)
    {
        if(m==0 )
            {
                if(n!=0)
                    return 0;
                else
                    return 1;
        }
        if( n==0)
        {
             while(m--)
            {
                if(p[m]=='*')
                {
                    m--;
                }
                 else  
                     return false;
            }
            return 1;
        }
        
        
        if(dp[n][m]!=-1)
            return dp[n][m];
        
        if(a[n-1]==p[m-1] || p[m-1]=='.' )
            return dp[n][m]=findans(a,p,n-1,m-1,dp);
        else
        {
            if(p[m-1]=='*')
            {
               int  val =findans(a,p,n,m-2,dp);
                if(p[m-2]==a[n-1]  || p[m-2]=='.' )
                val=val || findans(a,p,n-1,m,dp);
                return val;
               
                    
            }else
                return 0;
        }
        
    }
    bool isMatch(string a, string p) {
        
      
        int n = a.size(), m = p.size(); 
       
        vector<vector<int>>dp (n+1, vector<int>(m+1, -1));
        return findans(a,p,a.size(),p.size(),dp);
    }
};