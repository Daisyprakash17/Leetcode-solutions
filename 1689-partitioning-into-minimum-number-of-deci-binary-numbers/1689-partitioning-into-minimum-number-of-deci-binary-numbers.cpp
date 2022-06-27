class Solution {
public:
    int minPartitions(string n) {
        int val=-1;
        
        for(auto i:n)
            val=max(val,(i-'0'));
        return val;
    }
};