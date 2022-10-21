class Solution {
public:
    void fill(string &s ,int i,int j)
    {
        while(i<j)
        {
            s[i]='R';
            s[j]='L';
            i++;
            j--;
        }
    }
    string pushDominoes(string s) {
        int n=s.size();
        string ans=s;
        
        vector<pair<char,int>>val;
        for(int i=0;i<n;i++)
        {
            if(s[i]!='.')
                val.push_back({s[i],i});
        }
        if(val.size()>0)
        for(int i=0;i<val.size()-1;i++)
        {
            if(val[i].first=='R' && val[i+1].first=='L')
            {
                
                fill(ans,val[i].second,val[i+1].second); 
                i++;
            }
        }
        
        for(int i=0;i<n-1;i++)
            if(ans[i]=='R' && ans[i+1]=='.' )
                {
                    if(i+2<n && ans[i+2]=='L')
                        continue;
                ans[i+1]=ans[i];
            }
        for(int i=n-1;i>0;i--)
            if(ans[i]=='L' && ans[i-1]=='.')
                {
                if(i-2>=0 && ans[i-2]=='R')
                    continue;
                ans[i-1]=ans[i];
            }
        return ans;
                
            }
};