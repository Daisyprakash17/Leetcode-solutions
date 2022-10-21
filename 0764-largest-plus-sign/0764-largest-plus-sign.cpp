class Solution {
public:
    int orderOfLargestPlusSign(int n, vector<vector<int>>& mines) {
        vector<vector<int>>v(n,vector<int>(n,1));
        for(auto i:mines)
            v[i[0]][i[1]]=0;
        
        vector<vector<int>>row(n);
        vector<vector<int>>col(n);
        vector<vector<int>>prerow(n,vector<int>(n,0));
        vector<vector<int>>precol(n,vector<int>(n,0));
        for(int i=0;i<n;i++)
        {
            int last=-1;
            for(int j=0;j<n;j++)
            {
                if(v[i][j]==0)
                   { last=j;
                    row[i].push_back(j);
                   }
                else
                    prerow[i][j]=last;
                
            }
            row[i].push_back(n);
        }
        for(int j=0;j<n;j++)
        {
            int last=-1;
            for(int i=0;i<n;i++)
            {
                if(v[i][j]==0)
                   { last=i;
                    col[j].push_back(i);
                   }
                else
                    precol[i][j]=last;
            }
            col[j].push_back(n);
        }
        
        int ans=0;
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(v[i][j]==0)
                    continue;
                int left=j-prerow[i][j];
                int top=i-precol[i][j];
                left--;
                top--;
                auto it=lower_bound(row[i].begin(),row[i].end(),j);
                int right=(*it)-(j+1);
                it=lower_bound(col[j].begin(),col[j].end(),i);
                int down=(*it)-(i+1);
                  ans=max(ans,1+min({left,right,top,down}));
            }
        }
        return ans;
    }
    
};