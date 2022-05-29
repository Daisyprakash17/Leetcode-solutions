class Solution {
public:
     bool isvalid(vector<vector<char>>&v,int r,int c,int n)
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
    string val="123456789";
     bool findans(vector<vector<char>>&v,int i,int j)
     {
         
          if(j==9)
         {
             j=0;
             i++;
         }
           if(i==9)
             return true;// this means we have reached to the last
         
         
         // is this is already filled so call for the next cell
         if(v[i][j]!='.')
             return findans(v,i,j+1);
         
         
         for(int k=0;k<9;k++)
         {
              
             v[i][j]=val[k];
             if(isvalid(v,i,j,9)==true )
             {
                 // is this value in this cell is not valid 
                 // then back track at this cell and return false
                 // which will denote the fact that the steps before this 
                 // was also wrong
                 int res=findans(v,i,j+1);
                 if(res==1)
                     return true;
             }
         }
         v[i][j]='.';
         return false;
         
     }
    void solveSudoku(vector<vector<char>>& v) {
        
         
        findans(v,0,0);
        
    }
};