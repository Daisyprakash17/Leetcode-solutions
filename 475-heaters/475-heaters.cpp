class Solution {
public:
    int findRadius(vector<int>& h, vector<int>& hh) {
        int n=h.size();
        vector<pair<int,int>>temp;
        for(int i=0;i<n;i++)
            temp.push_back({INT_MAX,INT_MAX});
        
        sort(h.begin(),h.end());
        sort(hh.begin(),hh.end());
        
        for(int i=0;i<n;i++)
        {
            auto it=lower_bound(hh.begin(),hh.end(),h[i]);
            if(it!=hh.end())
            {
                temp[i].second=*it-h[i];
            }
        }
        
        vector<pair<int,int>>helper;
        for(auto i:h)
            helper.push_back({i,1});
        
        for(auto i:hh)
            helper.push_back({i,-1});
        sort(helper.begin(),helper.end());
        
        int in=INT_MAX;
        int count=0;
        for(auto i:helper)
        {
            if(i.second<0)
                in=i.first;
            else
            {
                if(in!=INT_MAX) 
                    temp[count].first=i.first-in;
                count++;
            }
                
        }
        int ans=-1; 
        for(auto i:temp)
        
            ans=max(ans,min(i.first,i.second));        
        return ans;
        
    }
};