class Solution {
public:
    int countSubarrays(vector<int>& nums, int k) {
        
        int i=0;
        int n=nums.size();
        for(;i<n;i++)
        {
            if(nums[i]==k)
                break;
        }
        int high=0;
        int low=0;
        map<int,int>m;
        int ans=0; 
        
        m[0]=1;
        for(int j=i+1;j<n;j++)
        {
            if(nums[j]>k)
                high++;
            else
                low++;
            
            m[high-low]++;
        }
        ans+=m[0];
        ans+=m[1];  
        high=0;
        low=0;  
        for(int j=i-1;j>=0;j--)
        {
            if(nums[j]>k)
                high++;
            else
                low++;
            int diff=high-low; 
            ans+=m[diff*-1];
            ans+=m[(diff*-1)+1];  
            
         }
        return ans;
        
    }
};