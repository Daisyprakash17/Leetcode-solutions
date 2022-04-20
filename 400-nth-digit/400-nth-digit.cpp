class Solution {
public:
    int findNthDigit(int n) { 
        
        int count=1;
        if(n<10)
            return n;
        while(n>(count*9*(pow(10,count-1))))
        {
            n-=count*9*pow(10,count-1);
            count++;
            
            
        }
        int mod=n%count;
        int fac=n/count;
        int num=pow(10,count-1)+fac;
        if(mod==0)
        {
            return (num-1)%10;
        }
        string s=to_string (num);
        return s[mod-1]-'0';
    }
};