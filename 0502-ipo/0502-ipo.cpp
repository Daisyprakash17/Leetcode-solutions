class Solution {
public:
    
    int findMaximizedCapital(int k, int w, vector<int>& p, vector<int>& c)      {
        
        
        priority_queue<int>q;
                 vector<pair<int,int>>v;
        for(int i=0;i<p.size();i++) 
            v.push_back({c[i],p[i]}); 
        sort(v.begin(),v.end());
        int i=0; 
        while(k>0)
        {
              for(i;i<v.size();i++)
              {
                  if(v[i].first>w)
                      break;
                  q.push({v[i].second });
              }
            if(q.size()==0)
                break;
             
            
            w+=q.top();
            q.pop();
            k--;
        }
        
        return w;
    }
};