class Solution {
public:
    void merge(vector<int>& nums1, int n, vector<int>& nums2, int m) {
         int i=n-1;
        int j=m-1;
        int k=nums1.size()-1;
        while(j>=0 && i>=0)
        {
            if(nums1[i]>=nums2[j])
            {
                nums1[k]=nums1[i];
                i--;
                k--;
            }
            else
            {
                nums1[k]=nums2[j];
                k--;
                j--;
            }
        }
        // if i is >=0 then run this loop
        while(i>=0)
        {
             nums1[k]=nums1[i];
                i--;
                k--;
        }
        
        while(j>=0)
        {
            nums1[k]=nums2[j];
                k--;
                j--;
        }
    }
};