class Solution {
public: 
    vector<vector<int>>ans;
    map<int,int>m;
    void findans(vector<int>v,int i,int sum,int k,int n)
    {
        if(i>=10)
        {
             
             
            if(v.size()==k && sum==n)
                ans.push_back(v);
            return ;
        }
        
        // if not considering first 
        findans(v,i+1,sum,k,n);
        // if considering 
        v.push_back(i);
        sum+=i;
        findans(v,i+1,sum,k,n);
    }
    vector<vector<int>> combinationSum3(int k, int n) {
             
        
        vector<int>temp;
        findans(temp,1,0,k,n);
        return ans;
    }
};