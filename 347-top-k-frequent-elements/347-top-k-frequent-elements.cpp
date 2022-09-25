class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
         priority_queue<pair<int,int>,vector<pair<int,int>>,greater< pair<int,int>>>q;
        map<int,int>m;
        for(auto i:nums)
            m[i]++;
        for(auto i:m)
        {
            q.push({i.second,i.first});
            if(q.size()>k)
                q.pop();
        }
        vector<int>ans;
        while(q.size()>0)
        {
            ans.push_back(q.top().second);
            q.pop();
            }
        return ans;
    }
};