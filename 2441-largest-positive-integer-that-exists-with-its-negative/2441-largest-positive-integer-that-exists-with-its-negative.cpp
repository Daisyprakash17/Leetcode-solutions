class Solution {
public:
    int findMaxK(vector<int>& nums) {
        
        map<int,int>m;
        int ans=-1;
        for(auto i:nums){
            if(m[-1*i]>0){
                ans=max(ans,abs(i));
            }
            m[i]++;
        }
        return ans;
    }
};