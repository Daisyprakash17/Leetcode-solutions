class Solution {
public:
    int minOperations(vector<int>& a, vector<int>& b) { 
            int g=b[0];
        
        for(int i=1;i<b.size();i++)
            g=__gcd(g,b[i]);
        int count=0;
        sort(a.begin(),a.end());
        
        for(auto i:a)
            if(g%i==0)
                break;
        else
            count++;
        
        if(count==a.size())
            count=-1;
        return count;
    }
};