class Solution {
public:
    int trap(vector<int>& v) {
        
        int n=v.size();
        vector<int>pre(n);
        vector<int>suf(n);
        pre[0]=v[0];
        suf[n-1]=v[n-1];
        for(int i=1;i<n;i++)
            pre[i]=max(v[i],pre[i-1]);
        
        for(int i=n-2;i>=0;i--)
        suf[i]=max(v[i],suf[i+1]);
        
        long long  ans=0;
        for(int i=0;i<n;i++)
        {
            int val=min(pre[i],suf[i])-v[i];
            if(val>0)
                ans+=val;
        }
        return ans;
    }
};