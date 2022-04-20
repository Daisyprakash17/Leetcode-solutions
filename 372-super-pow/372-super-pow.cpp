class Solution {
public:
     int mod=1337;
    int binpow(int a,int b,int mod)
    {
        
        a=a%mod;
        long long int res=1;
        while(b>0)
        {
            if(b&1)
                res=res*a%mod;
            a=a*a%mod;
            b=b>>1;
        }
        return res;
    }
    int superPow(int a, vector<int>& b) {
         
       if(b.size()==0)
           return 1;
        int last=b.back();
        b.pop_back();
        return (binpow(superPow(a,b),10,mod)%mod)*binpow(a,last,mod)%mod;
    }
};