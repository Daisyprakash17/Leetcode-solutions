class Solution {
public:
    
    string shiftingLetters(string s, vector<vector<int>>& ss) {
       int n=s.size();
        vector<int>v(n+1,0);
        
        for(auto i:ss)
        {
            if(i[2]==0)
            {
                v[i[0]]--;
                v[i[1]+1]++;
                
            }
            else
            {
                v[i[0]]++;
                v[i[1]+1]--;
            }
        }
        for(int i=1;i<=n;i++)
        {
            v[i]+=v[i-1];
        }
        
        for(int i=0;i<n;i++)
        {
            if(v[i]>=0)
            {
                v[i]%=26;
                while(v[i]-->0)
                {
                    if(s[i]=='z')
                        s[i]='a';
                    else
                        s[i]++;
                }
            }
            else
            {
                v[i]*=-1;
                v[i]%=26;
                while(v[i]-->0)
                {
                    if(s[i]=='a')
                        s[i]='z';
                    else
                        s[i]--;
                }
            }
        }
        return s;
    }
};