class Solution {
public:
    int first(vector<int>v,int num)
    {
        int index=-1;
        
        int low=0;
        int high=v.size()-1;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(v[mid]==num)
            {
                index=mid;
                high=mid-1;
            }
            else if(v[mid]>num)
                high=mid-1;
            else
                low=mid+1;
        }
        return index;
    }
    int last(vector<int>v,int num)
    {
        int index=-1;
        int low=0;
        int high=v.size()-1;
        while(low<=high)
        {
            int mid= low+(high-low)/2;
            if(v[mid]==num)
            {
                index=mid;
                low=mid+1;
            }
            else if(v[mid]>num)
            {
                high=mid-1;
            }
            else
                low=mid+1;
        }
        return index;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int a=first(nums,target);
        int b=last(nums,target);
        vector<int>v;
        v.push_back(a);
        v.push_back(b);
        return v;
    }
};