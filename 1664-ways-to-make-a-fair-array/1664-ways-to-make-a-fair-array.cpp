class Solution {
public:
    int waysToMakeFair(vector<int>& nums) {
        int sum1=0;
        int sum2=0;
        for(int i=0;i<nums.size();i++)
        {
            if(i%2==0)
                sum1+=nums[i];
            else
                sum2+=nums[i];
        }
        int o=0;
        int e=0;
        
        int count=0;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            if(i%2==0){
            sum1-=nums[i];
            if((e+sum2)==(o+sum1))
                count++;
                e+=nums[i];
                
            }else{
                
                sum2-=nums[i];
                if((e+sum2)==(o+sum1))
                    count++;
                
                o+=nums[i];
            }
        }
        return count;
    }
};