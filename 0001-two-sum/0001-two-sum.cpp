class Solution {
public:
    vector<int> twoSum(vector<int>& v, int target) {
       
        vector<pair<int,int>>nums;
        for(int i=0;i<v.size();i++)
            nums.push_back({v[i],i});
        sort(nums.begin(),nums.end());
            
        int i=0;
        int j=nums.size()-1;
        while(i<j)
        {
            int sum=nums[i].first+nums[j].first;
            if(sum==target)
                return {nums[i].second,nums[j].second};
            if(sum>target)
                j--;
            if(sum<target)
                i++;
            
        }
        return {0,0};
    }
};