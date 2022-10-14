class Solution {
public:
    long long maxi(long long first ,long long second)
    {
        if(first>second)
        return first;
        return second;
    }
    long long mini(long long first ,long long second)
    {
        if(first>second)
            return second;
        return first;
    }
    int maxProductPath(vector<vector<int>>& v) {
        int mod=1000000007;
        int n,m;
            n=v.size();
            m=v[0].size();
        
        vector<vector<pair<long long ,long long >>>val(n,vector<pair<long long ,long long >>(m,{LONG_MAX,LONG_MIN}));
        // we will be find the min and max for each index
         
        val[n-1][m-1].first=val[n-1][m-1].second=v[n-1][m-1];
        
        
        for(int i=n-1;i>=0;i--)
        {
            for(int j=m-1;j>=0;j--)
            {
                    long long  mi=(val[i][j].first);
                    long long  ma=(val[i][j].second);
             
                if(i-1>=0)
                {
                    long long  first=(mi*v[i-1][j]);
                    long long  second=(ma*v[i-1][j]);
                val[i-1][j].first=mini(val[i-1][j].first,mini(first,second));
                val[i-1][j].second=maxi(val[i-1][j].second,maxi(first,second));
                }
                if(j-1>=0)
                {
                    long long  first=(mi*v[i][j-1]);
                    long long  second=(ma*v[i][j-1]);
                val[i][j-1].first= mini(val[i][j-1].first,mini(first,second));
                val[i][j-1].second=maxi(val[i][j-1].second,maxi(first,second));
                
                    
                }
            }
        }
        long long  res=val[0][0].second;
       
            if(res>=0)
                return res%mod;
        return -1;
    }
};