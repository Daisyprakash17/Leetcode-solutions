class NumMatrix {
public:
    vector<vector<int>>temp;
    NumMatrix(vector<vector<int>>& v) {
        
        int n=v.size();
        int m=v[0].size();
        
        for(int i=0;i<n;i++){
            int sum=0;
            for(int j=1;j<m;j++){
                    v[i][j]+=v[i][j-1];
                }
        }
        
        for(int j=0;j<m;j++){
            for(int i=1;i<n;i++){
                v[i][j]+=v[i-1][j];
            }
        }
        temp=v;
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        
        int ans=0;
        ans+=temp[row2][col2];
        if((row1-1)>=0)
            ans-=temp[row1-1][col2];
        if((col1-1)>=0)
            ans-=temp[row2][col1-1];
        if((row1-1)>=0 && (col1-1)>=0)
            ans+=temp[row1-1][col1-1];
        return ans;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */