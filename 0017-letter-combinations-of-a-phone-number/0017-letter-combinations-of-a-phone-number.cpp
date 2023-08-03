class Solution {
public:
    vector<string>ans;
    map<int,string >m;
    void findans(string &d,int i,string   temp)
    {
            if(i>=d.size())
            {
                ans.push_back(temp);
                return ;
            }
        
        for(auto val:m[d[i]-'0'])
        {
            temp.push_back(val);
            findans(d,i+1,temp);
            temp.pop_back();
        }
    }
    vector<string> letterCombinations(string d) {
            int n=    d.size();
        if(n==0)
            return ans;
        m[2]="abc";
        m[3]="def";
        m[4]="ghi";
        m[5]="jkl";
        m[6]="mno";
        m[7]="pqrs";
        m[8]="tvu";
        m[9]="wxyz"; 
        string temp;
        findans( d,0,temp);
        return ans;
    }
};