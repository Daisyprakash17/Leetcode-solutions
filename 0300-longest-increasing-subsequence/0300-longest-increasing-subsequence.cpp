class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int>v;
        v.push_back(nums[0]);
        
        for(int i=1;i<nums.size();i++)
        {
            int j=v.size();
            if(nums[i]>v[j-1])
                v.push_back(nums[i]);
            else
            {
                int ind=lower_bound(v.begin(),v.end(),nums[i])-v.begin();
                if(ind<j)
                    v[ind]=nums[i];
            }
        } 
        return v.size();
    }
};