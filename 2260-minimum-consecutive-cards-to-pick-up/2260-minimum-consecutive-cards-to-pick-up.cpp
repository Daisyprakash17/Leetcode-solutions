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
            if(i.second.size()>1)
            {
                for(int j=1;j<i.second.size();j++)
                {
                    ans=min(ans,i.second[j]-i.second[j-1]);
                }
            }
        }
        if(ans==INT_MAX)
            return -1;
        else
            return ans+1;
    }
    
};