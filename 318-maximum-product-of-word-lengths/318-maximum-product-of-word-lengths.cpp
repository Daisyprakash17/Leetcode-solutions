
class Solution {
public:
    int maxProduct(vector<string>& words) {
        vector<pair<int,long long >>vals;
        for(auto i:words)
        {
            long long   val=0; 
            for(auto j:i)
            {
                 val|= (1<<(j-'a'));
            }
            vals.push_back({i.size(),val});
        }
        int final_ans=0;
        for(int i=0;i<words.size();i++)
        {
            for(int j=i+1;j<words.size();j++)
            {
                if((vals[i].second& vals[j].second)==0)
                {
                    final_ans=max(final_ans,vals[i].first*vals[j].first);
                }
            }
        }
        return final_ans;
    }
};