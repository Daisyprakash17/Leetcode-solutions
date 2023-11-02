class Solution {
public:
    int dp[1001];
    int findans(int i,vector<vector<int>>&v,int w){
        if(i>=v.size())
            return 0;
        
        if(dp[i]!=-1)
            return dp[i];
        
        int ans=INT_MAX;
        int ma=0;
        int ww=w;
        for(int j=i;j<v.size();j++){
            if(ww>=v[j][0])
            {
                ma=max(ma,v[j][1]);
                ans=min(ans,ma+findans(j+1,v,w));
                ww-=v[j][0];
            }
            else{
                break;
            }
        }
            return dp[i]=ans;
        
            
    }
    int minHeightShelves(vector<vector<int>>& b, int w) {
        memset(dp,-1,sizeof(dp));
        return findans(0,b,w);
    }
};