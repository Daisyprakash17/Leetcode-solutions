class Solution {
public:
    int getval(int cur,int pre)
    {
        int low=1;
        int high=1e9;
        int ans=1;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            int temp=cur/mid;
            if(cur%mid!=0)
                temp++;
            if(temp<=pre)
            {
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }
    long long minimumReplacement(vector<int>& nums) {
        long long ans=0;
        int n=nums.size();
        int pre=nums[n-1];
        for(int i=n-2;i>=0;i--)
        {
            if(nums[i]<pre)
            {
                pre=nums[i];
            }
            else{
                int val=getval(nums[i],pre);
                ans+=(val)-1;
                pre=nums[i]/val;
            }
        }
        return ans;
    }
};