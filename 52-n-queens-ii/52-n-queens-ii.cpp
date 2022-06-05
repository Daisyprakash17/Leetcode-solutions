class Solution {
public:
    int ans=0;// this is to store the total diffrent variation
    
    bool ifsafe(vector<string>&temp_grid,int i,int j,int n)
    {
        int x;// row 
        int y;// column
        
        
        // first left cheking for the left diaganal 
        x=i-1;
        y=j-1;
        while(x>=0 && y>=0)
        {
            if(temp_grid[x][y]=='Q')
                return false;
            x--;
            y--;
        }
        
        // now cheking for right diagonal
        x=i-1;
        y=j+1;
        while(x>=0 && y<n)
        {
            if(temp_grid[x][y]=='Q')
                return false;
            x--;
            y++;
        }
        
        // now cheking in the all the above column 
        x=i-1;
        while(x>=0)
        {
            if(temp_grid[x][j]=='Q')
                return false;
            x--;
        }
        return true;
    }
    void findans(vector<string>&temp_grid,int i,int n)
    {
        if(i>=n)
        {
            // incrementing the and variable and returing the control
            ans++;
            return ;
        }
        
        for(int j=0;j<n;j++)
        {
            if(ifsafe(temp_grid,i,j,n))
            { 
                temp_grid[i][j]='Q';
                findans(temp_grid,i+1,n);
                temp_grid[i][j]='.';// here we are backtracking
            }
        }
    }
    int totalNQueens(int n) {
        vector<string>temp_grid(n,string(n,'.')); 
        findans(temp_grid,0,n);
        return ans;
    }
};