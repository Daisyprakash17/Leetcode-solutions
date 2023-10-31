class Solution {
public:
     static bool cmp(vector<int>&a,vector<int>&b)
    {
        if(a[0]==b[0])
            return a[1]>b[1];
        return a[0]<b[0];
    }
    int maxEnvelopes(vector<vector<int>>& v) {
        // this problem is the variation of longest increasing sequence
        // lis which is solved using binary search
        
        sort(v.begin(),v.end(),cmp);
        vector<int>temp;
        for(auto i:v)
            temp.push_back(i[1]);
        vector<int>ans;
        
        for(auto i:temp){
            if(ans.size()==0)
            {
                ans.push_back(i);
                continue;
            }
            int h=i;
            int ind=lower_bound(ans.begin(),ans.end(),h)-ans.begin();
            
            if(ind==ans.size())
            {// this means the current element is the largest in the ans 
                //vector
                ans.push_back(i);
            }else{
                // else we will replace the value if the index
                ans[ind]=i;
            }
        }
        return ans.size();
    }
};