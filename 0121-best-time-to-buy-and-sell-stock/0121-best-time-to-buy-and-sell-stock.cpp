class Solution {
public:
    int maxProfit(vector<int>& v) {
        int n=v.size();
         int val=v[0];
        int final_ans=0;
        for(int i=1;i<n;i++)
        { 
            if(v[i]>=val)
            final_ans=max(final_ans,v[i]-val);
            val=min(val,v[i]);
        }
        
       return final_ans;
    }
};