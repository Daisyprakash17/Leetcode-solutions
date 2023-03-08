class Solution {
public:
    
//     1000 -> 0 ==15
//     1000 -> 1110 == 4
//     1110 -> 0 == 11
        
//         so
        
//         0 ->110 == 4
//         0 ->1110 ==11
//         0 ->1000 == 15
        
//         so we can conclude that 
        
//         X(1110)+ X(110) = X(1000)
//         x(1110)= x(1000)- x(110)
        
        
        
    int minimumOneBitOperations(int n) {
        if(n<=1)
            return n;
        int bit=0;
        for(int i=0;i<31;i++)
        {
            if((n&(1<<i))==(1<<i))
                bit=i;
        } 
        int temp=1<<bit; 
        return (2*temp-1) - minimumOneBitOperations(n^temp);
    }
};