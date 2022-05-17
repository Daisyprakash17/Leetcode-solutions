class Solution {
public:
    int minSteps(string s, string t) {
        
        map<char,int>m;
        for(auto i:s)
            m[i]++;
        for(auto i:t)
            m[i]--;
        
        int count=0;
        for(auto i:m)
            count+=abs(i.second);
        return count/2;
        
    }
};