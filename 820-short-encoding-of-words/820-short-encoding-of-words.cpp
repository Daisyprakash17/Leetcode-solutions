class Solution {
public:
    int minimumLengthEncoding(vector<string>& v) {
        map<string ,int >m;
        vector<pair<int,string>>vv;
        
        for(auto i:v)
        {
            m[i]++;
            vv.push_back({i.size(),i});
        }
        sort(vv.rbegin(),vv.rend());
        
        int count=0;
        for(auto i:vv)
        { 
            if(m[i.second]>0)
            {
                 count+=i.second.size()+1;
                m[i.second]=0;
                for(int j=0;j<i.second.size();j++)
                {
                    string temp=i.second.substr(j,7);
                     if(m[temp]>0)
                    {
                        m[temp]=0;
                    }
                }
            }
        }
        return count;
    }
};