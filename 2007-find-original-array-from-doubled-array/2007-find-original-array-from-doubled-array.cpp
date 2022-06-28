class Solution {
public:
     
    vector<int> findOriginalArray(vector<int>& arr) {
        if(arr.size()%2==1)
            return {};
          map<int,int>m;
        for(auto i:arr)
            m[i]++;
         vector<int>first;
        sort(arr.begin(),arr.end());
        
        for(auto i:arr)
        {
            if(m[i]>0)
            {
                if(m[2*i]>0)
                {
                    m[i]--;
                    m[2*i]--;
                    first.push_back(i);
                }
                else
                {
                    vector<int>t;
                    return t;
                }
            }
        }
        return first;
    }
};