class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& v, vector<int>& people) {
        map<int,int>m;
        for(auto i:v){
            m[i[0]]++;
            m[i[1]+1]--;
        }
        int count=0;
        int pre=0;
        vector<pair<int,int>>val;
        for(auto i:m)
        {
            val.push_back({pre,count});
            count+=i.second;
            pre=i.first;
        }
        val.push_back({pre,0});
        vector<int>ans;
        
        for(auto i:people)
        { 
            auto it=lower_bound(val.begin(),val.end(),make_pair(i,0));
            if(it==val.end())
            {
                ans.push_back(0);
                continue;
            }
            if((*it).first!=i)
                it--;
        ans.push_back((*it).second);
        }       
        
        return ans;
    }

};