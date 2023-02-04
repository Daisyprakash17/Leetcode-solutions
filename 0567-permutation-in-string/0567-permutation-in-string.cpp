class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        
        if(s1.size()>s2.size())
            return false;
        map<char,pair<int,int>>m;
        for(auto i:s1)
            m[i].first++;
        int flag=true;
        
        int n=s1.size();
        
        for(int i=0;i<s2.size();i++)
        {
            m[s2[i]].second++;
            if(i>=n)
            {
                m[s2[i-n]].second--;
            }
            if(i>=n-1)
            {
                flag=true;
                for(auto i:m)
                {
                    if(i.second.first!=i.second.second)
                    {
                        flag=false;
                        break;
                    }
                }
                if(flag==true)
                    break;
            }
        }
        
       return flag;
    }
};