 
class Solution {
public:
    
    int reverse(int x) {
       
       int flag=0;  
        if(x<0)
        {  
            flag=1; 
            x=x*-1ll;
        }
          
        
            long long int val=0; 
        while(x>0)
        {
            val=(val*10)+x%10;
             x=x/10;
        }
        
        if(flag==1)
            val*=-1; 
        int left=(1ll<<31)*-1;
        int right=(1ll<<31)-1;
             if( (val<left) || (val>right))
            return 0;
        return val;
        
        
        
    }
};