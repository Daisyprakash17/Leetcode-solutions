class NumMatrix {
public:
    vector<vector<int>>grid;
    NumMatrix(vector<vector<int>>& matrix) {
        
        int n=matrix.size();
        int m=matrix[0].size();
        for(int i=0;i<n;i++)
        {
            vector<int>temp;
            temp.push_back(0);
            
            for(int j=1;j<=m;j++)
            {
               temp.push_back(matrix[i][j-1]+temp[j-1]);
            }
            grid.push_back(temp);
        }
       
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        
        int sum=0;
        for(int r=row1;r<=row2;r++)
        {
             sum+=grid[r][col2+1]-grid[r][col1];
        }
        return sum;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */