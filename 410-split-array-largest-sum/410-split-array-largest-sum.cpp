class Solution {
public:
    int getvalue(vector<int>&nums,int val)
    {
        int  count=1;
        int sum=0;
        
        for(auto i:nums)
        {
            if(sum+i<=val)
            {
                sum+=i;
            }
            else
            {
                sum=i;
                count++;
            }
        }
        return count;
    }
    int findans(vector<int>&nums,int m)
    {
     
        int low=-1;
        int high=0;
        for(auto i:nums)
        {
            low=max(low,i);
            high+=i;
        }
        int ans=0;
        
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            
            int val=getvalue(nums,mid);
            if(val<=m)
            {
                ans=mid;
                high=mid-1;
            }
            else
                low=mid+1;
        }
        return ans;
         
    }
    int splitArray(vector<int>& nums, int m) {
        return findans(nums,m);
    }
};