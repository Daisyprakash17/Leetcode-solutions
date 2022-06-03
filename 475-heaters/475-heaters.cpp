class Solution {
public:
    int findRadius(vector<int>& h, vector<int>& hh) {
        int n=h.size();
        int m=hh.size();
        
        sort(h.begin(),h.end());
        sort(hh.begin(),hh.end());
        int in=0;
        int ans=-1;
        for(int i=0;i<n;i++)
        {
            auto it=lower_bound(hh.begin(),hh.end(),h[i]);
            int right=INT_MAX;
            int left=INT_MAX;
            if(it!=hh.end())
            {
                right=*it-h[i];
            }
            
            if(hh[in]>h[i])
            {
                ans=max(ans,right);
                continue;
            }
            
            while(in+1<m)
            {
                if(hh[in+1]<=h[i])
                {
                    in++;
                }
                else
                {
                    break;
                }
            }
              left=h[i]-hh[in];
            ans=max(ans,min(left,right));
            
            
        }
             
        return ans;
        
    }
};