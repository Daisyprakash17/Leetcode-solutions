class Solution {
public:
    map<int,vector<int>>m;
    vector<vector<string>>ans;
    void findans(string &s,int in)
    {
        if(in>=s.size())
            return ;
        
        if(m[in].size()>0)
            return ;
        
        for(int j=in;j<s.size();j++)
        {
            int i=in;
            int k=j;
            int flag=1;
            while(i<=k)
            {
                if(s[i]!=s[k])
                {
                    flag=0;
                    break;
                }
                i++;
                k--;
            }
            if(flag)
            {
                m[in].push_back((j-in)+1);
                findans(s,j+1);
            }
        }
        
        
    }
    void getans(int i,string &s,vector<string >temp)
    {
        if(i>=s.size())
        {
            ans.push_back(temp);
            return ;
        }
        
        for(auto j:m[i])
        {
            vector<string >tt;
            tt=temp;
            string ss=s.substr(i,j);
            tt.push_back(ss);
            getans(i+j,s,tt);
            
        }
    }
    vector<vector<string>> partition(string s) {
        findans(s,0);   
        vector<string >temp;
        getans(0,s,temp);
        return ans;
    }
};