class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
       
        sort(nums.begin(),nums.end());
        int flag=0;
        int ans=-1;
        if(nums.size()==1)
        {
                if(nums[0]==1)
                    return 2;
            else
                return 1;
        }
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]<=0)
                continue;
            else
            {
                if(nums[i]==1)
                {
                    flag=1;
                }
                if(i+1>=nums.size())
                    continue;
                int diff=(nums[i+1]-nums[i]);
                if(diff<=1)
                    continue;
                else
                    {
                    ans= nums[i]+1;
                     break;
                    }
            }
    }
        if(flag==0)
            return 1;
        else if(ans!=-1)
            return ans;
        else
        return nums[nums.size()-1]+1;
    }
};