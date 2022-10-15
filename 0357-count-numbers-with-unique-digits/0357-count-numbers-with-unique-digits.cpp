class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        vector<int>v(9,0);
        
        v[0]=0;
        v[1]=9;
        v[2]=90;
        
        
        for(int i=3;i<=n;i++)
        {
            int k=i-1;
            int val=9;
            int sum=val;
            while(k--)
            {
                sum*=val;
                val--;
            } 
            v[i]=sum+v[i-1];
        }
        return v[n]+1;
    }
};