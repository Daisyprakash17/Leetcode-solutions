class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& v, int target) {
        int n=v.size();
        int m=v[0].size();
        
        for(int i=0;i<n;i++)
        {
            for(int j=1;j<m;j++)
                v[i][j]+=v[i][j-1];
        }
        
        int ans=0;
          unordered_map<int,int>mm;
        for(int start=0;start<m;start++)
        {
            for(int last=start;last<m;last++)
            {
                
              
                int sum=0;
                mm[0]=1;
                    
                for(int row=0;row<n;row++)
                {
                    sum+=v[row][last]-(start>0?v[row][start-1]:0);
                    ans+=mm[sum-target];
                    mm[sum]++;
                }
                mm.clear();
            }
        }
        return ans;
        
    }
};