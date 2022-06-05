class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& v) {
        vector<int>ans;
        
        int n=v.size();
        int m=v[0].size();
        int pos=1;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                
                if(i==n-1 ||j==0 )
                {
                    vector<int>temp;
                    int x=i;
                    int y=j;
                    while(x>=0 && y<m)
                    {
                        temp.push_back(v[x][y]);
                        x--;
                        y++;
                    }
                    
                    if(pos==1)
                    {
                        pos=0;
                    }
                    else
                    {
                        pos=1;
                        reverse(temp.begin(),temp.end());
                    }
                    for(auto i:temp)
                        ans.push_back(i);
                }
            }
        }
        return ans;
    }
};