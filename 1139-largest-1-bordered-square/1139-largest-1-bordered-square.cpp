class Solution {
public:
    int n,m;
    int check(int i,int j,vector<vector<int>>&row,vector<vector<int>>&col,int k)
    {
        int count=0;
        
        if(j+k<m && row[i][j+k]>=k+1)
            count++;
        if(i+k<n && col[i+k][j]>=k+1)
            count++;
        
        if(i+k<n && j+k<m)
        {
            if(row[i+k][j+k]>=k+1)
                count++;
            if(col[i+k][j+k]>=k+1)
                count++;
            }
        return count==4;
        
    }
    int largest1BorderedSquare(vector<vector<int>>& v) {
        int ans=0;
          n=v.size();
          m=v[0].size();
        
        vector<vector<int>>row(n,vector<int>(m,0));
        vector<vector<int>>col(n,vector<int>(m,0));
        for(int i=0;i<n;i++)
        {
            int count=0;
            for(int j=0;j<m;j++)
            {
                if(v[i][j]==1)
                    count++;
                else
                    count=0;
                row[i][j]=count;
            }
        }
        
        for(int j=0;j<m;j++)
        {
            int count=0;
            for(int i=0;i<n;i++)
            {
                if(v[i][j]==1)
                    count++;
                else
                    count=0;
                col[i][j]=count;
            }
        }
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                
                for(int k=0;k<=99;k++)
                {
                    if(check(i,j,row,col,k))
                        ans=max(ans,k+1);
                }
        }
        }
        
        return ans*ans;
    
    }
};