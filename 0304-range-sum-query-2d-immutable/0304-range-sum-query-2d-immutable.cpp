class NumMatrix {
public:
    vector<vector<int>>v;
    NumMatrix(vector<vector<int>>& t) {
        
        int n=t.size();
        int m=t[0].size();
        for(int i=0;i<n;i++)
        {
            vector<int>temp;
            temp.push_back(t[i][0]);
            for(int j=1;j<m;j++)
                temp.push_back(temp[j-1]+t[i][j]);
            
            v.push_back(temp);
        }
         
        for(int j=0;j<m;j++)
        {
            for(int i=1;i<n;i++)
                v[i][j]+=v[i-1][j];
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
         
        int sum=v[row2][col2];
        if(row1-1>=0)
            sum-=v[row1-1][col2];
        if(col1-1>=0)
            sum-=v[row2][col1-1];
        if(row1-1>=0 && col1-1>=0)
            sum+=v[row1-1][col1-1];
        return sum;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */