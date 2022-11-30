class Solution {
public:
    long long countSubarrays(vector<int>& nums, int mi, int ma) {
        
        vector<int>mini;
        vector<int>maxi;
        int n=nums.size();
        map<int,vector<int>>m;
        for(int i=0;i<n;i++)
        {
            if(nums[i]<mi)
                mini.push_back(i);
            
            if(nums[i]>ma)
                maxi.push_back(i);
            
            if(nums[i]==mi)
                m[mi].push_back(i);
            if(nums[i]==ma)
                m[ma].push_back(i);
        }
        mini.push_back(n);
        maxi.push_back(n);
         
        long long  ans=0;
        
        for(int i=0;i<n;i++)
        {
            if(nums[i]>=mi && nums[i]<=ma)
            {
                // now i just have to find the bound and then range
                
              auto   it=lower_bound(m[mi].begin(),m[mi].end(),i);
                if(it==m[mi].end())
                    break;
                int val=*it;
                it=lower_bound(m[ma].begin(),m[ma].end(),i);
                if(it==m[ma].end())
                    break;
                val=max(val,*it); 
                // so now i am having the range 
                // now i this range is just have to check 
                // that all values should be great the mi and smaller than ma
                
                  it=lower_bound(mini.begin(),mini.end(),i);
                auto itt=lower_bound(maxi.begin(),maxi.end(),i);
                if(  ((*it)<i || (*it)>val) &&    (*itt<i ||  *itt>val))
                {
                    // then only we can get the answer 
                     int temp;
                    auto it=lower_bound(maxi.begin(),maxi.end(),val);
                     temp=(*it)-val;
                     it=lower_bound(mini.begin(),mini.end(),val);
                     temp=min(temp,(*it)-val);
                    
                     ans+=temp;
                 }
            }
         }
        return ans;
    }
};