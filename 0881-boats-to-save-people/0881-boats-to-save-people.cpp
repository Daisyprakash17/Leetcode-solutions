class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int count=0;
        multiset<int>s;
        for(auto i:people)
            s.insert(i);
        
        while(s.size()){
            int val=*s.begin();
            s.erase(s.begin());
            int diff=limit-val;
            auto it=s.lower_bound(diff+1);
            if(it!=s.begin())
            {
                it--;
                s.erase(it);
            }
            count++;
            
            
        }
        return count;
    }
};