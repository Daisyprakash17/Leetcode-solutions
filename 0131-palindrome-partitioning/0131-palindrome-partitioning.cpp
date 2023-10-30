class Solution {
public:
    vector<vector<string>>ans;
    bool check(string &s,int i,int j){
        
        while(i<=j)
        {
            if(s[i]!=s[j])
                return false;
            i++;
            j--;
        }
        return true;
    }
    void findans(string & s,int i,vector<string> &temp){
        if(i>=s.size())
        {
            ans.push_back(temp);
            return ;
        }
        for(int j=i;j<s.size();j++){
            if(check(s,i,j)){
                temp.push_back(s.substr(i,j-i+1));
                findans(s,j+1,temp);
                temp.pop_back();
            }
        }
        
    }
    vector<vector<string>> partition(string s) {
        vector<string>temp;
         findans(s,0,temp);
        return ans;
    }
};