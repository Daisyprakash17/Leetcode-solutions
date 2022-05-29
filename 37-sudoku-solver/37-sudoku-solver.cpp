class Solution {
public:
     bool isvalid(vector<vector<char>>&v,int r,int c,int n)
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