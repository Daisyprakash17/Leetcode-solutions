 
class Solution {
public:
    int count=0;
    int  getans(vector<int>&v,int low,int mid,int high)
    {
        vector<long long >t;
        for(int i=low;i<=mid;i++)
            t.push_back(v[i]);
        sort(t.begin(),t.end());
        int ans=0;
        for(int i=mid+1;i<=high;i++)
        {
            long long temp=v[i];
            auto it=lower_bound(t.begin(),t.end(),2*temp+1);
            if(it!=t.end())
                ans+=t.size()-(it-t.begin());
        }
         return ans;
    }
    
    void findans(vector<int>&v,int low,int high)
    {
        if(low==high)
            return;
        
        int mid=(low+high)/2;
        
        count+= getans(v,low,mid,high);
        findans(v,low,mid);
        findans(v,mid+1,high);
    }
    int reversePairs(vector<int>& nums) {
      findans(nums,0,nums.size()-1);
        return count;
    }
};
