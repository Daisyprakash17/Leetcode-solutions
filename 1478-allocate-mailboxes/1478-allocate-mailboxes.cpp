class Solution {
public:
    int dp[101][101];
    map<int,int>m;
    int getval(vector<int>&v,int i,int j)
    {
        if(i==j)
            return 0;
        int sum=0;
        for(int k=i+1;k<=j;k++)
            sum+=v[k];
        int ans=sum-(j-i)*v[i];
        int val=0;
        int left=1;
        int right=(j-i);
        for(int k=i+1;k<=j;k++)
        {
            val+=(v[k]-v[k-1])*left;
            ans=min(ans,val+(sum-(right*v[k])));
            left++;
            right--;
            sum-=v[k];
        }
        return ans;
    }
    int findans(vector<int>&v,int i,int n,int k)
    {
        if(i==n && k==0)
            return 0;
        if(i<n && k==0)
            return INT_MAX; // this means we should not consider this value
        if(dp[i][k]!=-1)
            return dp[i][k];
        
        int val=INT_MAX;
        
        for(int j=i;j<=n-k;j++)
        {
            int curval=findans(v,j+1,n,k-1);
            if(curval!=INT_MAX)
                val=min(val,curval+getval(v,i,j));
        }
        return dp[i][k]=val;
    }
    int minDistance(vector<int>& houses, int k) {
        memset(dp,-1,sizeof(dp));
        for(auto i:houses)
            m[i]++;
        sort(houses.begin(),houses.end());
        return findans(houses,0,houses.size(),k);
    }
};