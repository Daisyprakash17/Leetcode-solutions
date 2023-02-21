class Solution {
public:
    
    
    int get_ans(vector<int>v)
    {

        int low=0;
        int high=v.size()-1;
        while(low<high)
        {
            int mid=low+(high-low)/2;
            if(v[mid]==v[mid^1])
                low=mid+1;
            else
                high=mid;
        }
        return v[low];
    }
    int singleNonDuplicate(vector<int>& nums) {
        
        
        return get_ans(nums);
    }
};