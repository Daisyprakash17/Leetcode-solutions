class Solution {
public:
    bool find132pattern(vector<int>& nums) { 
        int n=nums.size();
        vector<int>v(n);
        v[0]=nums[0];
        set<int>s; 
        for(int i=1;i<n;i++)
        {
            
         v[i]=min(nums[i],v[i-1]); 
        }
        s.insert(nums[n-1]);
        for(int i=n-2;i>0;i--)
        { 
            
            int mi=v[i-1];
            if(nums[i]>mi)
            {
                auto it=s.lower_bound(mi+1);
                if(it!=s.end() && *it<nums[i])
                    return true;
            }
            s.insert(nums[i]);
        }
        return false;
        
        
    }
}; 