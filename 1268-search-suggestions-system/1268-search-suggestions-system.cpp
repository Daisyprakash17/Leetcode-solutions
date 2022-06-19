class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        
        map<string,set<string>>ms;
        for(auto i:products)
        {
            string t="";
            for(int j=0;j<i.size();j++ )
            {
                t+=i[j];
                ms[t].insert(i);
            }
        }
        
        vector<vector<string >>ans;
        string s="";
        for(auto i:searchWord)
        {
            s+=i;
            vector<string>temp;
            int sz=ms[s].size();
            sz=min(sz,3);
            if(sz==0)
            {
                ans.push_back(temp);
                continue;
            }
                 auto it=ms[s].begin();
            while(sz--)
            {
                temp.push_back(*it);
                it++;
            }
            ans.push_back(temp);
        }
        return ans;
    }
};