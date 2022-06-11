class Solution {
public:
    
    
    int minOperations(vector<int>& nums, int x) {
        int n=nums.size();
        vector<int>pre(n);
        vector<int>suf(n);
        pre[0]=nums[0];
        for(int i=1;i<n;i++)
            pre[i]=pre[i-1]+nums[i];
        
        suf[n-1]=nums[n-1];
        for(int i=n-2;i>=0;i--)
            suf[i]=suf[i+1]+nums[i];
    
        int ans=INT_MAX;
        auto it=lower_bound(pre.begin(),pre.end(),x);
        if(it!=pre.end() && *it==x)
        {
            ans=(it-pre.begin())+1;
        }
        for(int i=n-1;i>=0;i--)
        {  
            
            if(suf[i]<=x)
            {
                int val=x-suf[i];
                
                if(val==0)
                {
                    ans=min(ans,n-(i));
                    continue;
                }
                auto it=lower_bound(pre.begin(),pre.end(),val);
                if(it!=pre.end()   )
                {
                    int in=it-pre.begin(); 
                    if(in<i && *it==val) 
                         ans=min(ans,in+1+(n-i)); 
                }
            }
        }
        if(ans==INT_MAX)
            return -1;
            else
        return ans;
    }
};