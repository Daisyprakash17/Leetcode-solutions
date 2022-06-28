class Solution {
public:
    bool check(vector<int>arr)
    {
         map<int,int>m;
        for(auto i:arr)
            m[i]++;
        sort(arr.begin(),arr.end());
        
        for(auto i:arr)
        {
            if(m[i]>0)
            {
                if(m[2*i]>0)
                {
                    m[i]--;
                    m[2*i]--;
                }
                else
                    return false;
            }
        }
        return true;
    }
    bool canReorderDoubled(vector<int>& arr) {
        
         vector<int >first,second;
        for(auto i:arr)
            if(i>=0)
                first.push_back(i);
        else
            second.push_back(-1*i);
        if(check(first) && check(second))
            return true;
        else
            return false;
    }
    
};