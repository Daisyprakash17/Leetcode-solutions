class Solution {
public:
    
    bool findans(vector<vector<char>>&v,int r,int c,int n)
    {
        
        int i=3*(r/3);
        int j=3*(c/3);
         map<int,char>m;
        for(int k=i;k<i+3;k++)
        {
            for(int l=j;l<j+3;l++)
            {
                if(v[k][l]!='.')
                m[v[k][l]]++;
            }
        }
         for(auto i:m)
            if(i.second>1)
                return false;
        
         for(int j=0;j<n;j++)
        {
            if(j!=r && v[j][c]==v[r][c])
                return false;
        }
        
         for(int j=0;j<n;j++)
        {
            if(j!=c && v[r][j]==v[r][c])
                return false;
        }
        
         return true;
        
        
    }
    bool isValidSudoku(vector<vector<char>>& v) {
        
        int n=9;
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(v[i][j]!='.' && !findans(v,i,j,n))
                {
                   
                  return false;
                    
                }
            }
        }
        
        return true;
    }
};