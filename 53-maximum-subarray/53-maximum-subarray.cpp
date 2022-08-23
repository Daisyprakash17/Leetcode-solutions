class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum=0;
        int maxi;
        
        for(int i=0;i<nums.size();i++)
        {
            if(i==0)
            {
                sum=nums[0];
                maxi=nums[0];
            }
            else
                sum+=nums[i];
            
                maxi=max(sum,maxi);
            if(sum<0)
                sum=0;
            
        }
        return maxi;
    }
};