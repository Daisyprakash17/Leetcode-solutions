class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        if(n==1)
            return nums[0];
        
        long long  ans=0;
        // because the ans is always going to be non negative
        
        long long  neg=1; 
        long long  pro=1;
        for(int i=0;i<n;i++)
        {
            if(nums[i]==0)
            {
                neg=1; 
                pro=1;
            }
            else
            {
                pro*=nums[i];
                if(pro>0)
                    ans=max(ans,pro);
                else
                {
                    if(neg!=1)
                        ans=max(ans,pro/neg);
                    else
                        neg=pro;
                }
            }
            
            
        }
        return ans;
    }
};