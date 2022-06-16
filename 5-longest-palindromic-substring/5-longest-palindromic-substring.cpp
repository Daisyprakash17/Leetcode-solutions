class Solution {
public:
    string findans(string s,int n)
    {
        for(int k=0;k<=s.size()-n;k++)
        {
            int i=k;
            int j=k+(n-1);
            
            int flag=1;
            while(i<=j)
            {
                if(s[i]!=s[j])
                {
                    flag=0;
                    break;
                }
                i++;
                j--;
                    
            }
            if(flag)
                return s.substr(k,n);
        }
        return "##";
    }
    string longestPalindrome(string s) {
        
        
        for(int i=s.size();i>0;i--)
        {
            string  val=findans(s,i);
            if(val!="##")
                return val;
        }
        return "";
    }
};