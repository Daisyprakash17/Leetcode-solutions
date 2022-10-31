class Solution {
public:
    int dp[101][101][21];
    int findans(vector<int>&v,vector<vector<int>>&cost,int i,int j,int k)
    {
        if(j>k || (i==v.size() && j!=k))
            return INT_MAX;
        if(i==v.size() && j==k)
            return 0;
        //cout<<i<<" "<<j<<" "<<k<<" "<<dp[i][j]<<" "<<v[i]<<endl;
         if(i-1>=0 && dp[i][j][v[i-1]]!=-1 )
            return dp[i][j][v[i-1]];
        
         
        if(v[i]!=0)
        {
            int val;
            // already color
             if(i-1>=0 && v[i-1]==v[i]) {
                val=findans(v,cost,i+1,j,k);}
            else {
                val=findans(v,cost,i+1,j+1,k);}
            
            if(i-1>=0)
        return dp[i][j][v[i-1]]=val;
        else
            return val;
        }
        int val=INT_MAX;
        int temp;  
        for(int t=0;t<cost[0].size();t++)
        {
            v[i]=t+1;
            
            if(i-1>=0 && v[i-1]==t+1) // consider the previous color
               {
                 temp= findans(v,cost,i+1,j,k);
                
            }
            
            else
                {
                 temp=findans(v,cost,i+1,j+1,k); }// cosidering new color
            if(temp!=INT_MAX)
                val=min(val,cost[i][t]+temp);
        } 
        // changind the color to 0 so that we can select again new values for that
        v[i]=0;
        if(i-1>=0)
        return dp[i][j][v[i-1]]=val;
        else
            return val;
    }
    int minCost(vector<int>& v, vector<vector<int>>& cost, int m, int n, int k) {
        memset(dp,-1,sizeof(dp));
        int res=findans(v,cost,0,0,k);
        if(res==INT_MAX)
            return -1;
        else
            return res;
    }
};