class Solution {
public:
    void merge(vector<int>& nums1, int n, vector<int>& nums2, int m) {
         int i=n-1;
        int j=m-1;
        int k=nums1.size()-1;
        //  scanning both the array from the back 
        // and also keeping the pointer the last locationg of 
        // first array and pushing the maximum value out of the 
        // array and decreamenting the last location index
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
        
        // running the loop if j>=0 so push all the value from this
        while(j>=0)
        {
            nums1[k]=nums2[j];
                k--;
                j--;
        }
    }
};