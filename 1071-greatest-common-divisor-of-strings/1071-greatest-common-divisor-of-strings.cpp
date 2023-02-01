class Solution {
public:
    string gcdOfStrings(string s, string t) {
        string ans="";
        
        string temp;
        for(int i=0;i<t.size();i++)
        {
            temp+=t[i];
            int sz=i+1;
            
            int flag=1;
            for(int j=0;j<s.size();j+=sz)
            {
                if(s.substr(j,sz)!=temp)
                {
                    flag=0;
                    break;
                }
            }
            for(int j=0;j<t.size();j+=sz)
            {
                if(t.substr(j,sz)!=temp)
                {
                    flag=0;
                    break;
                }
            }
            if(flag)
                ans=temp;
        
        }
        return ans ;
    }
};