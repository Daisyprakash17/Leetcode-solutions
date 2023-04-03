class Solution {
public:
    long long countGood(vector<int>& v, int k) {
        long long ans=0;
        map<long long ,long long >mi;
        map<long long ,long long >mj;
        int i=0;
        int j=0;
        long long sum=0;
        mj[v[0]]=1; 
        int n=v.size(); 
        while(1)
        {
            if(sum>=k)
            {
                ans+=n-j;
                mi[v[i]]++;
                sum-=mj[v[i]]-mi[v[i]];
                i++; 
                continue;
            }
            j++; 
            for(;j<n;j++)
            {
                sum+=mj[v[j]]-mi[v[j]]; 
                mj[v[j]]++;
                if(sum>=k)
                {
                    break;
                }
            } 
            if(sum>=k)
            {
                ans+=n-j;
            }
            if(j==n)
                break;
            mi[v[i]]++;
            sum-=mj[v[i]]-mi[v[i]];
            i++; 
            
        }
        return ans;
    }
};