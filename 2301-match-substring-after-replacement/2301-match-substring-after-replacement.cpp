class Solution {
public:
     
    bool matchReplacement(string s, string t, vector<vector<char>>& mappings) {
        map<char,set<int>>mm; 
        for(auto i:mappings)
        {
            int val=i[1];
            mm[i[0]].insert(val);
        } 
         
        int n=s.size();
        int m=t.size();
        for(int i=0;i<=n-m;i++)
        {
            int k=0;
            int flag=1;
            for(int j=0;j<m;j++,k++)
            {
                
                if(s[i+k]==t[j])
                { 
                    continue;
                }
                else
                {
                    int val=s[i+k];
                    auto it=mm[t[j]].find(val);
                    if(it==mm[t[j]].end())
                    {
                        flag=0;
                        break;
                    }
                }
            }
            if(flag)
                return true;
        }
        
        return false;
    }
};