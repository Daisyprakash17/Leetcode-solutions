class Solution {
public:
    int compress(vector<char>& s) {
        char c=s[0];
        int cnt=1;
        int j=0;
        for(int i=1;i<s.size();i++)
        {
            if(s[i]==c)
                cnt++;
            else
            {
                if(cnt==1) 
                    s[j++]=c;  
                else
                {
                    s[j++]=c; 
                    for(auto k:to_string(cnt))
                        s[j++]=k;
                }
                cnt=1;
                c=s[i];
            }
        }
                if(cnt==1) 
                    s[j++]=c;  
                else
                {
                    s[j++]=c; 
                    for(auto k:to_string(cnt))
                        s[j++]=k;
                }
        return j;    
    }
    
};