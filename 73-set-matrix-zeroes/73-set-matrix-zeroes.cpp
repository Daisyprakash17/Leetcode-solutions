class Solution {
public:
    void setZeroes(vector<vector<int>>& v) {
        int n=v.size();
        int m=v[0].size();
        vector<pair<int,int>>in;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(v[i][j]==0)
                    in.push_back({i,j});
            }
        }
        
        for(auto i:in)
        {
            for(int j=0;j<m;j++)
                v[i.first][j]=0;
            for(int j=0;j<n;j++)
                v[j][i.second]=0;
        }
    }
};