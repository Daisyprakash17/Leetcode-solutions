class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
       int n=cost.size();
        vector<int>v(n,INT_MAX);
        
        v[n-1]=0;
        v[n-2]=0;
        
        for(int i=n-1;i>=0;i--)
        {
            int val=v[i]+cost[i];
            v[i]=val;
            if(i-1>=0)
                v[i-1]=min(v[i-1],val);
            
            if(i-2>=0)
                v[i-2]=min(v[i-2],val);
        }
        return min(v[0],v[1]);
    }
};