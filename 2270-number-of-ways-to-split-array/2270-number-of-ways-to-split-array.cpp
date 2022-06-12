class Solution {
public:
    int waysToSplitArray(vector<int>& v) {
       
        vector<long long >nums;
        for(auto i:v)
            nums.push_back(i);
         long long sum=0;
        sum+=nums[0];
        for(int i=1;i<nums.size();i++)
        {
            sum+=nums[i];
            nums[i]+=nums[i-1];
             
        }
        int count=0;
        for(int i=0;i<nums.size()-1;i++)
        {
            if(nums[i]>=(sum-nums[i]))
                count++;
        }
        return count;
    }
};