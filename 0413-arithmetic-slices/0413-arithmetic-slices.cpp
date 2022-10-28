class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n=nums.size();
        vector<int>v;
        for(int i=1;i<n;i++)
            v.push_back(nums[i]-nums[i-1]);
        
        
        if(v.size()==0)
            return 0;
        int count=1;
        int ans=0;
        int last=v[0];
        for(int i=1;i<v.size();i++)
        {
            if(v[i]==v[i-1])
            {
                count++;
            }
            else
            {
                last=v[i];
                if(count>1)
                    {
                    ans+=(count*(count+1)/2)-count;
                    count=1;
                }
            }
        }
        
                if(count>1)
                    {
                    ans+=(count*(count+1)/2)-count;
                    count=1;
                }
        return ans;
    }
    
};