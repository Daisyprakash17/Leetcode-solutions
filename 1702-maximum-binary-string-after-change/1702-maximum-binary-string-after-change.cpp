class Solution {
public:
    string maximumBinaryString(string s) {
        int one=0;
        int zero=0;
        for(auto i:s)
            if(i=='0')
                zero++;
        else
            one++;
        string ans; 
        for(auto i:s)
        {
                if(i=='0')
                    break;
            else
            {
                ans+='1';
                one--;
            }
        }
        for(int i=1;i<zero;i++)
            ans+='1';
        if(zero>0)
            ans+='0';
        for(int i=0;i<one;i++)
            ans+='1';
            return ans;
    }
};