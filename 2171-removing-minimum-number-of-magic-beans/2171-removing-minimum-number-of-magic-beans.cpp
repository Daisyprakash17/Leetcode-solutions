class Solution {
public:
    long long minimumRemoval(vector<int>& v) {
        
        int n=v.size();
        vector<long long  >sum(n,0);
        long long total=0;
        sort(v.begin(),v.end());
        sum[0]=v[0];
        total+=v[0];
        for(int i=1;i<n;i++) 
        {
            sum[i]+=v[i];
            total+=v[i];
        }
        long long  ans=total;
        
        for(int i=0;i<=100000;i++)
        {
        auto it=upper_bound(v.begin(),v.end(),i);
            if(it==v.end())
                continue;
            long long in=(it-v.begin()); 
        long long rem=total-( (*it)*(n-in)); 
            ans=min(ans,rem); 
        }
        return ans;
        
        }
};