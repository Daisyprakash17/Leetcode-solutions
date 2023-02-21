class Solution {
public:
    map<int,vector<pair<int,int>>>m;
    set<int>s; // this is the store the unique starting indexes
    map<pair<int,int>,int>dp; // this is to store the res of sub problem
   
    int findans(int i,int k)
    {
        if(dp.find({i,k})!=dp.end())
            return dp[{i,k}];
        
        auto it=s.lower_bound(i);
        int temp=0;
        while(it!=s.end() && k>0)
        {
            auto st=(*it);
            it++;
            
            for(auto j:m[st])
            {
                temp=max(temp,j.second+findans(j.first+1,k-1));
            }
        }
        return dp[{i,k}]=temp;
    }
    
    int maxValue(vector<vector<int>>& events, int k) {
        for(auto i:events){
            m[i[0]].push_back({i[1],i[2]});
            s.insert(i[0]);        
    }
        return findans(1,k);
    }
};