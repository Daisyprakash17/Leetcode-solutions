class Solution {
public:
    int minPathSum(vector<vector<int>>& v) {
        
        
        int n=v.size();
        int m=v[0].size();
        
        for(int j=m-1;j>=0;j--)
        {
            for(int i=n-1;i>=0;i--)
            {
                int val=INT_MAX;
                if(i+1<n)
                    val=min(val,v[i+1][j]);
                if(j+1<m)
                    val=min(val,v[i][j+1]);
                if(val==INT_MAX)
                    val=0;
                v[i][j]+=val;
            } 

        }
        return v[0][0];

    }
};