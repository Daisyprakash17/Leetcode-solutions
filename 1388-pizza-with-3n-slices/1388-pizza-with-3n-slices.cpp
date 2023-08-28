class Solution {
public:
    map<int,map<int,map<int,int>>>dp;
    int findans(int i,int left,int right,vector<int>&v,int last)
    {
        if(left+right+1==0)
            return 0;
        if(i>=last)
        {
            if( (left==0 && right==-2))
                return 0;
            else
                return INT_MIN;
        }
        if(dp[i][left][right]!=0)
            return dp[i][left][right];
        int ans=0;
        ans=max(v[i]+findans(i+2,left-1,right-2,v,last),findans(i+1,left+1,right-1,v,last));
        return dp[i][left][right]=ans;
    }
    int maxSizeSlices(vector<int>& v) {
        int n=v.size(); 
        int firsttaken=v[0]+findans(2,0,n-4,v,v.size()-1);
        int firstnottaken=findans(1,1,n-2,v,v.size());
        return max(firsttaken,firstnottaken);
    }
};