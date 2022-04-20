class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& v) {
        
        sort(v.begin(),v.end());
        
        int n=v.size();
        for(int i=1;i<n;i++)
        {
            if((v[i][0]<=v[i-1][1] && v[i][0]>=v[i-1][0]) || (v[i][0]<=v[i-1][1] && v[i][1]>=v[i-1][1]))
            {
                v[i][0]=min(v[i][0],v[i-1][0]);
                v[i][1]=max(v[i][1],v[i-1][1]);
                v[i-1][0]=-1;
                
            }
        }
        vector<vector<int>>ans;
        for(auto i:v)
            if(i[0]!=-1)
                ans.push_back(i);
        return ans;
    }
};