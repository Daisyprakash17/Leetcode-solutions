class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0)
            return 0;
         vector<int>t;
        map<int,int>m;
        for(auto i:nums)
            if(m[i]==0)
            {
                t.push_back(i);
                m[i]++;
            }
        sort(t.begin(),t.end()); 
    vector<int>v;
        for(int i=1;i<t.size();i++)
        {
            v.push_back(t[i]-t[i-1]);
        }
        int ans=0;
        int count=0; 
        for(auto i:v)
        {
            if(i==1)
                count++;
            else
            {
            ans=max(ans,count);
                count=0;
            }
        }
        ans=max(ans,count); 
        return ans+1;
    }
};