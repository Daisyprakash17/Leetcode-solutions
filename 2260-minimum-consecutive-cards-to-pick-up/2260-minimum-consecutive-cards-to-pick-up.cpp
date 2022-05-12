class Solution {
public:
    int minimumCardPickup(vector<int>& v) {
        map<int,vector<int>>m;
        for(int i=0;i<v.size();i++)
        {
                m[v[i]].push_back(i+1);
        }
            int ans=INT_MAX;
        for(auto i:m)
        {
            vector<int>v=i.second;
            if(v.size()>1)
            {
                for(int j=1;j<v.size();j++)
                {
                    ans=min(ans,v[j]-v[j-1]);
                }
            }
        }
        if(ans==INT_MAX)
            return -1;
        else
            return ans+1;
    }
    
};