class Solution {
public:
    static bool cmp(pair<int,int>&a,pair<int,int>&b)
    {
        if(a.first==b.first)
            return a.second>b.second;
        return a.first<b.first;
    }
    int findMaximizedCapital(int k, int w, vector<int>& p, vector<int>& c)      {
        
        
        priority_queue<pair<int,int>>q;
                 vector<pair<int,int>>v;
        for(int i=0;i<p.size();i++) 
            v.push_back({c[i],p[i]}); 
        sort(v.begin(),v.end(),cmp);
        int i=0; 
        while(k>0)
        {
              for(i;i<v.size();i++)
              {
                  if(v[i].first>w)
                      break;
                  q.push({v[i].second,v[i].first});
              }
            if(q.size()==0)
                break;
            auto it=q.top();
            q.pop();
            k--;
            w+=it.first;
        }
        
        return w;
    }
};