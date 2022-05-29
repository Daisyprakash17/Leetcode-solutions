class Solution {
public:
    
    bool findans(vector<vector<char>>&v,int r,int c)
    {
        
          char val=v[r][c];
         v[r][c]='.';
         int flag=1;
         
         for(int i=0;i<9;i++)
         {
             if(v[i][c]==val || v[r][i]==val)
             {
                 flag=0;
                 break;
             }
             
             if(v[3*(r/3)+i/3][3*(c/3)+i%3]==val)
             {
                 flag=0;
                 break;
             }
                 
         }
         
         v[r][c]=val;
         return flag;
        
        
        
    }
    bool isValidSudoku(vector<vector<char>>& v) {
        
        int n=9;
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(v[i][j]!='.' && !findans(v,i,j))
                {
                   
                  return false;
                    
                }
            }
        }
        
        return true;
    }
};