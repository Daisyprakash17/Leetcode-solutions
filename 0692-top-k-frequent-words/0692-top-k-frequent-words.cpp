class Solution {
public:
    static bool cmp(pair<int,string >a,pair<int,string>b)
    {
        if(a.first==b.first)
            return a.second<b.second;
        return a.first>b.first;
    }
    vector<string> topKFrequent(vector<string>& v, int k) {
        
        vector<pair<int,string>>temp;
        map<string,int >m;
        string last=v[0];
        int count=1;
        for(auto i:v)
        {
            m[i]++;
        }  
        for(auto i:m)
            temp.push_back({i.second,i.first});
        sort(temp.begin(),temp.end(),cmp);
        vector<string >res;
        for(int i=0;i<k;i++)
        {
            res.push_back(temp[i].second);
        }
        return res;
    }
};