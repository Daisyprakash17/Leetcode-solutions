class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& t) {
        
        int n=t.size();
        int m=t[0].size();
        
        vector<vector<int>>v(n,vector<int>(m,0));
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(i==0 || j==0)
                {
                    
                    multiset<int>s;
                    int ii=i;
                    int jj=j;
                    while(ii<n && jj<m)
                    {
                        s.insert(t[ii][jj]);
                        ii++;
                        jj++;
                    }
                    
                      ii=i;
                      jj=j; 
                    auto it=s.begin();
                    while(ii<n && jj<m)
                    {
                        v[ii][jj]=*it;
                        it++;
                        ii++;
                        jj++;
                    }
                    
                    
                }
            }
        }
        return v;
    }
};