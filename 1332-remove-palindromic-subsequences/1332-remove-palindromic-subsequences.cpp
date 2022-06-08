class Solution {
public:
    int removePalindromeSub(string s) {
        if(s.size()==0)
            return 0;
        else {
            string t;
            t=s;
            reverse(t.begin(),t.end());
            if(t==s)
                return 1;
            else
                return 2;
        }
    }
};