class Solution {
public:
    int dp[101][10001];
    int findans(int e,int f)
    {
        if(e==0 || f==0)
            return dp[e][f]=0;
        if(e==1 || f==1)
            return dp[e][f]=f;
        if(dp[e][f]!=-1)
            return dp[e][f];
        int mini=INT_MAX;
        int low=0;
        int high=f;
            while(low<=high)        { 
            int mid=low+(high-low)/2;
            int left=findans(e-1,mid-1);
            int right=findans(e,f-mid);
            int temp=1+max(left,right);
            if(left<right)
                low=mid+1;
            else
                high=mid-1;
            mini=min(mini,temp);
        }
        return dp[e][f]=mini;
        }
    int superEggDrop(int e, int f) {
        memset(dp,-1,sizeof(dp));
        return findans(e,f);
    }
};