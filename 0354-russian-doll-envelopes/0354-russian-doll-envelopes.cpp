class Solution {
public:
    static bool cmp(vector<int>&a,vector<int>&b)
    {
        if(a[0]==b[0])
            return a[1]>b[1];
        return a[0]<b[0];
    }
        int maxEnvelopes(vector<vector<int>>& envelopes) {
        
  sort(envelopes.begin(), envelopes.end(), cmp);
        vector<int> dp;
       vector<int>temp;
            
            // after sorting we just have to find the lis using the 
            // the binary which is going to run in n logn time complexicity
            
       for(auto i:envelopes)
           temp.push_back(i[1]);
            
            
        for (auto& env : temp) {
            int height = env;
            int left = lower_bound(dp.begin(), dp.end(), height) - dp.begin();
            
            if (left == dp.size()) dp.push_back(height);
            dp[left] = height;
            
           
        }
        return dp.size();
    }
	
};