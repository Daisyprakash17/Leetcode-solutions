class Solution {
public:
    int numSplits(string s) {
        map<char,int >right;
        map<char,int>left;
        int lc=0;
        int rc=0;
        for(auto i:s)
            right[i]++;
        rc=right.size();
        int count=0;
        for(auto i:s)
        {
            if(left[i]==0) 
                lc++;  
            left[i]++;
            
            
            if(right[i]==1) 
                rc--; 
            right[i]--;
            
            
            if(lc==rc)
                count++;
        }
        return count;
    }
};