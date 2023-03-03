class Solution {
public:
    
     // here we are using the 4D dp first and second for row and col
     // third to store the stitting arrangement of the pre row 
    // and fouth is used to maintain the arrangement for the current row
    int dp[8][8][256][256];
    int findans(vector<vector<char>>&v,int i,int j,int pre,int cur)
    {
         if(i==v.size())
        return 0; 
        
        // new row
        if(j==v[0].size())
          return   findans(v,i+1,0,cur,0);
        
        // if this state has been already calculated
        if(dp[i][j][pre][cur]!=-1)
            return dp[i][j][pre][cur] ;
        
        
        int temp=0;
        if(v[i][j]=='.'&&!(i-1>=0 && j+1<v[0].size() && v[i-1][j+1]=='@') && !(i-1>=0 && j-1>=0 &&v[i-1][j-1]=='@' ) && !(j-1>=0 && v[i][j-1]=='@'))
        {
            v[i][j]='@';
            // if it possible to put the student on the current seat of current row
            // then we will mark this seat in the current row to be occupied by the student and make 
            // a another recursive call 
          temp=max(temp, 1+ findans(v,i,j+1,pre,cur|(1<<j)));
            v[i][j]='.';
        }
        temp=max(temp,findans(v,i,j+1,pre,cur)); 
        return dp[i][j][pre][cur]=temp;
    }
    int maxStudents(vector<vector<char>>& v) {
       memset(dp,-1,sizeof(dp)); 
       return  findans(v,0,0,0,0);
            
    }
};