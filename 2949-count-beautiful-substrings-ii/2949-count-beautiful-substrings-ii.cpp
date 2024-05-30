class Solution {
public:
    #define ll long long
    
    bool isvowel(char ch) {return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';}
    
    ll beautifulSubstrings(string s, int k) {
        ll a = 0, b = 0, ans = 0;
        unordered_map<ll, unordered_map<ll, ll>> mp;
        mp[0][0] = 1;
        
        for (char ch: s) {
            ++(isvowel(ch) ? a : b);
            
            for (auto& [z, count]: mp[a-b])
                if ((a-z)*(a-z) % k == 0) ans += count;
            
            ++mp[a-b][a%k];
        }
        
        return ans;
    }
};