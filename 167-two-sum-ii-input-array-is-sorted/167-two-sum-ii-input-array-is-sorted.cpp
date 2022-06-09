class Solution {
public:
    vector<int> twoSum(vector<int>& v, int target) {
        vector<int>ans;
        for(int i=0;i<v.size()-1;i++)
        {
            
            auto it=lower_bound(v.begin()+i+1,v.end(),target-v[i]);
            if(it==v.end())
                continue;
             if(i+1!=(it-v.begin()+1) && (v[i]+(*it))==target)
            {
                ans.push_back(i+1);
                ans.push_back(it-v.begin()+1);
                return ans;
            }
        }
        return ans;
    }
};