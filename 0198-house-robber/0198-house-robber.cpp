class Solution {
public:
    
    
    int rob(vector<int>& nums) {
        if(nums.size()==1)
            return nums[0];
        else if(nums.size()==2)
            return max(nums[0],nums[1]); 
        
        
        int prev1=nums[0];
        int prev2=0;
        int cur;
        for(int i=1;i<nums.size();i++)
        {
              cur=max(nums[i]+prev2,prev1);
            prev2=prev1;
            prev1=cur;
                    
        }
        return cur;
        
    }
};