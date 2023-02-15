class Solution {
public:
    void fillm(map<int,vector<int>>&m,string s)
    { 
        int n=s.size();
        for(int i=n-1;i>=0;i--)
        {
            int val=0; 
            if(s[i]=='0')
            {
                m[0]={i,i};
                continue;
            }
            for(int j=i;j<min(n,i+30);j++)
            {
                if(s[j]=='1')
                    val++;
                m[val]={i,j};
                val=val*2;
            }
        }
    }
    vector<vector<int>> substringXorQueries(string s, vector<vector<int>>& t) {
            map<int,vector<int>>m;
        fillm(m,s);
        vector<vector<int>>res;
        for(auto i:t)
        {
            int temp=i[0]^i[1];
            if(m.find(temp)!=m.end())
                res.push_back(m[temp]);
            else
                res.push_back({-1,-1});
        }
        return res;
            
    }
};