class Solution {
public:
    vector<vector<string >>ans;
    bool check(int i,int j,string &s)
    {
        while(i<=j)
        {
            if(s[i]!=s[j])
                return false;
            i++;
            j--;
        }
        return true;
    }
    void findans(int i,string &s,vector<string >&temp)
    {
        if(i>=s.size())
        {
            ans.push_back(temp);
            return ;
        }
        
        for(int j=i;j<s.size();j++)
        {
            if(check(i,j,s))
            {
                string ss=s.substr(i,j-i+1);
                temp.push_back(ss);
                findans(j+1,s,temp);
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<string >temp;
        findans(0,s,temp);
        return ans;
    }
};