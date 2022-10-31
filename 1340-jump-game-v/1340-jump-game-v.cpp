class Solution {
public:
    int dp[1001];
    int findans(vector<int>&arr,int i,int d)
    {
        if(i>=arr.size() ||i<0)
            return 0;
        if(dp[i]!=-1)
            return dp[i];
        
        int val=1;
        for(int j=1;j<=d && i+j<arr.size();j++)
        {
            if(arr[i]<=arr[i+j]  )
                break;
            val=max(val,1+findans(arr,i+j,d));
        }
        
        for(int j=1;j<=d && i-j>=0;j++)
        {
            if(arr[i]<=arr[i-j]  )
                break;
            val=max(val,1+findans(arr,i-j,d));
        }
        return dp[i]=val;
    }
    int maxJumps(vector<int>& arr, int d) {
        memset(dp,-1,sizeof(dp));
        int n=arr.size();
        int ans=0;
        for(int i=0;i<n;i++)
        {
            ans=max(ans,findans(arr,i,d));
        }
        return ans;
    }
    
};