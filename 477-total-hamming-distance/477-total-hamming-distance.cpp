class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        
        int ans=0;
        int n=nums.size();
        map<int,int>m;
        for(int i=0;i<n;i++)
        {
            int val=nums[i];
            
            for(int j=0;j<31;j++)
            {
                if((val&(1<<j))==(1<<j))
                    m[j]++;
            }
        }
        for(auto i:m)
            ans+=i.second*(n-i.second);
        return ans;
    }
};