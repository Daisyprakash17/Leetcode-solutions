class Solution {
public:
    int maxSatisfaction(vector<int>& v) {
        int sum=0;
        vector<int>pos,neg;
        for(auto i :v)
        {
                if(i>=0)
                {
                    pos.push_back(i);
                    sum+=i;
                }
            else
            {
                neg.push_back(i);
            }
                    
        }
        sort(pos.rbegin(),pos.rend());
        sort(neg.rbegin(),neg.rend());
        for(auto i:neg)
        {
            if(sum+i>=0)
            {
                pos.push_back(i);
                sum+=i;
            }
        }
        int ans=0;
        reverse(pos.begin(),pos.end());
        for(int i=0;i<pos.size();i++)
        {
            
            ans+=pos[i]*(i+1);
        }
        return ans;
    }
};