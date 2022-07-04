class Solution {
public:
    int peopleAwareOfSecret(int n, int d, int f) {
            
         
        vector<long long >ne(2500,0); 
        vector<long long >old(2500,0);
            
        long long  cur=0;
        long long  val=1;
        ne[1+d]=1;
        old[1+f]=1;
        long long  mod=1000000007;
        for(int i=2;i<=n;i++)
        {
            
            // removal of forgeted people
            cur=(cur-old[i]);
            val=(val-old[i]);
            
            // addition if new people
            cur=(cur+ne[i])%mod;
            ne[i+d]=cur;
            old[i+f]=cur;
            
            val=(val+cur)%mod;
            
            
        
        }
        return (val+mod)%mod;
    }
};