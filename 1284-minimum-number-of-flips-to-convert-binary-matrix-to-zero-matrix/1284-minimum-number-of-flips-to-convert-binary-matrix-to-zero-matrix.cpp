class Solution {
public:
    
    /*
     actual solution from 
     https://leetcode.com/problems/minimum-number-of-flips-to-convert-binary-matrix-to-zero-matrix/discuss/446712/C%2B%2B-easy-recursive-solution.
    */
    int n,m;
     
    vector<vector<int>>& change(vector<vector<int>>&arr,int i,int j)
    {
        arr[i][j]^=1;
        if(i+1<n)arr[i+1][j]^=1;
        if(j+1<m)arr[i][j+1]^=1;
        if(i-1>=0)arr[i-1][j]^=1;
        if(j-1>=0)arr[i][j-1]^=1;
        return arr;
    }
    
    bool check(vector<vector<int>>&arr)
    {
        for(auto i:arr)
            for(auto j:i)
                if(j==1)
                    return false;
        return true;
    }
    
    int flipornotflip(vector<vector<int>>arr,int i,int j)
    {
         if (j==m)
        {
             i++;
            j=0;
        }
        
        if(i==n)
        {
          if(check(arr)==true)
             return 0;
            else
                return INT_MAX-1;
        }
         int first=flipornotflip(arr,i,j+1);
         int second=flipornotflip(change(arr,i,j),i,j+1)+1;
        return min(first,second);
    }
    
    int minFlips(vector<vector<int>>& mat) {
        
         n=mat.size();
         m=mat[0].size();
         int ans=flipornotflip(mat, 0,0);
        if(ans>=INT_MAX-1)
            return -1;
        else
            return ans;
    }
};