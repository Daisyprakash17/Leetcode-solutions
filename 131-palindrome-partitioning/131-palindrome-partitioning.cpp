class Solution {
public:
    int dp[20][20];
    map<int,set<int>>m;
    vector<vector<string>>ans;
    bool findans(string &s,int i,int j)
    {
        if(i>j)
            return true;
        if(i==j)
        {
            m[i].insert(1);
            return true;
        }
        bool res=false;
        if(s[i]==s[j] && findans(s,i+1,j-1))
        {
            res=true;
            m[i].insert(j-i+1);  
        }
        findans(s,i+1,j);
        findans(s,i,j-1);
        return dp[i][j]=res;
            
    }
    void getans(vector<string>temp,int i,string& s)
    {
        if(i==s.size())
        {
            ans.push_back(temp);
            return ;
        }
        
        for(auto l:m[i])
        {
            string ss=s.substr(i,l);
            temp.push_back(ss);
            getans(temp,i+l,s);
            auto it=temp.end();
            it--;
            temp.erase(it);
        }    
    }
    vector<vector<string>> partition(string s) {
        memset(dp,-1,sizeof(dp));
        findans(s,0,s.size()-1);
         
        vector<string>temp;
        getans(temp,0,s);
        return ans;
    }
};