class Solution {
public:
    string getHint(string s, string g) {
        int count=0;
        map<int,int>a,b;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]==g[i])
                { 
                count++;
            }
            else
            {
                a[s[i]]++;
                b[g[i]]++;
            }
        }
        
        int res=0; 
        for(auto i:b) 
            res+=min(i.second,a[i.first]); 
        
        return  to_string(count)+"A"+to_string(res)+"B";
    }
};