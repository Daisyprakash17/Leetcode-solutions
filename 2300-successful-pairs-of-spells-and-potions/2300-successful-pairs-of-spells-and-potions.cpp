class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& p, long long success) {
        sort(p.begin(),p.end());
        
        vector<int>ans;
        for(auto i:spells)
        {
            long long  val=success/i;
            long long  re=success%i;
            if(re>0)
                val++;
            
            auto it=lower_bound(p.begin(),p.end(),val);
            if(it==p.end())
            {
                ans.push_back(0);
            }
            else
            {
                int temp=it-p.begin();
                ans.push_back(p.size()-temp);
            }
        }
        return ans;
    }
};