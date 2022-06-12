class Solution {
public:
    int maximumUniqueSubarray(vector<int>& s) {
         long long  ans=-1;
        int count=0; 
        vector<long long >pre;
        pre.push_back(0); 
        
        // her e
        for(int i=1;i<=s.size();i++)
        {
            long long cur=s[i-1];
            pre.push_back(cur+pre[i-1]);
        }
        // last index where problem arises
        int last=0; 
        map<int,int>m;  
        set<pair<int,int>>ss;
        for(int i=0;i<s.size();i++)
        {
        
            if(m[s[i]]!=0 && m[s[i]]>last)
            {
                // so i will do something
                 
                
                last=m[s[i]]; 
                auto it=ss.begin();
                while(it!=ss.end()  && (*it).first<=last)
                {
                    m.erase((*it).second);
                    ss.erase(it);
                    it=ss.begin();
                }
            }
            m[s[i]]=i+1;
            ss.insert({i+1,s[i]});
            ans=max(ans,pre[i+1]-pre[last]);
        }
        return ans;
    }
};