class Solution {
public:
    long long countSubarrays(vector<int>& nums, int mi, int ma) {
        int n=nums.size();
        int last=n;
        
        int mini=INT_MAX; // least index of mi value
        int maxi=INT_MAX; // least index of ma value
        long long sum=0;
        for(int i=n-1;i>=0;i--){
            if(nums[i]>ma || nums[i]<mi){
                last=i;
                mini=INT_MAX;
                maxi=INT_MAX;
            }
            else{
                if(nums[i]==mi)
                    mini=i;
                 if(nums[i]==ma)
                    maxi=i;
                
                if(mini==INT_MAX || maxi==INT_MAX)
                    continue;
                
                int maazi=max(mini,maxi);
                sum+=last-maazi;
                
            }
        }
        return sum;
    }
};