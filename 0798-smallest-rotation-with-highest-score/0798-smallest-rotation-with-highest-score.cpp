class Solution {
public:
    int bestRotation(vector<int>& v) {
        int n=v.size();
        vector<vector<pair<int,int>>>t(n+1,vector<pair<int,int>>());
        
        for(int i=0;i<n;i++)
        {
            int in=v[i];
            if(i<in)
            {
                t[i+1].push_back({1,in});
                t[i+1+(n-1-in)+1].push_back({-1,in});
             }
            else
            {
                t[0].push_back({1,in});
                t[i-in+1].push_back({-1,in});
                 t[i+1].push_back({1,in});
                t[n].push_back({-1,in});
             }
        }
        int ans=-1;
        int in=0;
        multiset<int>s; 
        for(int i=0;i<n+1;i++)
        { 
            for(auto j:t[i])
            {  
                if(j.first==1)
                    s.insert(j.second);
                else
                {
                    auto it=s.find(j.second);
                    s.erase(it);
                }
                
            }  
            
            int val=s.size();
            cout<<s.size()<<endl;
            if(val>ans)
            {
                ans=val;
                in=i;
            }      
        } 
        return in;
            

    }
};