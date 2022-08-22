class Solution {
public:
    int findval(long long val,long long  div)
    {
        val++;
        int count=val/div;
        count*=(div/2);
        int res=val%div; 
        res-=(div/2);
        if(res<0)
            res=0;
        return count+res;
    }
    int rangeBitwiseAnd(int ll , int rr ) {
       
         
         
        long long l=ll;
        long long r=rr;
        long long diff=(r-l)+1;
        if(l>0)
            l--;
        long long ans=0; 
        for(int i=0;i<=30;i++)
        {
            long long val=(1ll<<i);  
           
            int left=findval(l,2*val);
            int right=findval(r,2*val);  
            if((right-left)==diff)
                ans+=(1<<i);
        }
        return ans;
    }
};