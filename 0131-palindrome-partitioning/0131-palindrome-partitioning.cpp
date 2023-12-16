class Solution {
public:
    vector<vector<vector<string>>>ans;
    bool check(string& s,int i,int j){
        while(i<=j)
        {
            if(s[i]!=s[j])
                return false;
            i++;
            j--;
        }
        return true;
    }
    void findans(string s,int i){
        
        if(i>=s.size())
            return ;
        if(ans[i].size()>0)
            return ;
        
        for(int j=i;j<s.size();j++){
            if(check(s,i,j)){
                vector<string>temp;
                temp.push_back(s.substr(i,j-i+1));
                if(j+1==s.size()){
                    ans[i].push_back(temp);
                }else{
                findans(s,j+1);
                    for(auto k:ans[j+1]){
                        vector<string>t=temp;
                        for(auto a:k){
                            t.push_back(a);
                        }
                        ans[i].push_back(t);
                    }
                }
            }
        }
    }
    vector<vector<string>> partition(string s) {
        ans.resize(16);
        findans(s,0);
        return ans[0];
    }
};