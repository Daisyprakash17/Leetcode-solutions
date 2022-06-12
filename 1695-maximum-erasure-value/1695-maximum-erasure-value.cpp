class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int sum=0;
        int i=0; 
        int ans=0;
        map<int,int>m;
        for(int j=0;j<nums.size();j++)
        {
            sum+=nums[j];
            m[nums[j]]++;
            
            while(m[nums[j]]!=1)
            {
                m[nums[i]]--;
                sum-=nums[i];
                i++;
                
            }
            ans=max(ans,sum);
        }
        return ans;
    }
};