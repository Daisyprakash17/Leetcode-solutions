class Solution {
public:
    int minMoves(vector<int>& nums) {
        
        sort(nums.begin(),nums.end());
        int ans=0;
        int n=nums.size();
        for(int i=n-1;i>0;i--)
        {
            ans+=(nums[i]-nums[i-1])*(n-i);
        }
        return ans;
    }
};