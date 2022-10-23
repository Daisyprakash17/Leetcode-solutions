class Solution {
public:
    int pre[101][101];
    bool  check(int i,int j,int k,int l,int t)
    {
        
        int sum=pre[k][l];
        if(i-1>=0 && j-1>=0)
            sum+=pre[i-1][j-1];
        if(i-1>=0)
            sum-=pre[i-1][l];
        if(j-1>=0)
            sum-=pre[k][j-1];
        return sum==t;
    }
    int numSubmatrixSumTarget(vector<vector<int>>& v, int target) {
        int n=v.size();
        int m=v[0].size();
        memset(pre,0,sizeof(pre));
        for(int i=0;i<n;i++)
        {
            pre[i][0]=v[i][0];
            for(int j=1;j<m;j++)
            {
                pre[i][j]=pre[i][j-1]+v[i][j];
            }
        }
        
        for(int j=0;j<m;j++)
        {
            pre[0][j]=pre[0][j];
            for(int i=1;i<n;i++)
                pre[i][j]+=pre[i-1][j];
        }
        
        int ans=0;
        
     
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                for(int k=i;k<n;k++)
                {
                    for(int l=j;l<m;l++)
                    {
                        if(check(i,j,k,l,target))
                            ans++;
                    }
                }
            }
        }
        return ans;
        
    }
};