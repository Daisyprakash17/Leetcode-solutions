class Solution {
public:
    int findmax(vector<int>&v,int i,int j ){
        int val=v[i];
        for(int k=i+1;k<=j;k++)
            val=max(val,v[k]);
        return val;
    }
    int dp[41][41];
    int findans(vector<int>&v,int i,int j){
        
        if(i==j){
          return  dp[i][j]=v[i];
        }
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        int ans=INT_MAX;
        
        for(int k=i;k<j;k++){
           int leftval= findans(v,i,k);
           int rightval= findans(v,k+1,j);
            int left=findmax(v,i,k);
            int right=findmax(v,k+1,j);
            ans=min(ans,left*right+rightval+leftval);
        }
        return dp[i][j]=ans;
        
    }
    int mctFromLeafValues(vector<int>& arr) {
        memset(dp,-1,sizeof(dp));
        int sum=0;
        for(auto i:arr)
            sum+=i;
        return findans(arr,0,arr.size()-1)-sum;
    }
};