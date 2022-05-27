class Solution {
public:
    int longestPalindrome(vector<string>& v) {
        
        map<string ,int>m;
        for(auto i:v)
            m[i]++;
        
        int count=0;
        
        for(auto i:m)
        {
            string t=i.first;
            string s=i.first;
            swap(s[0],s[1]);
            int val;
            if(t!=s)
              val=min(m[t],m[s]);
            else
            {
                val=m[t]/2;
            }
            m[t]-=val;
            m[s]-=val;
            count+=4*val;
            
        }
        
        for(auto i:m)
            if(i.second>0 &&(i.first[0]==i.first[1]))
            {
                return count+2;
            }
    return count;        
        
    }
};