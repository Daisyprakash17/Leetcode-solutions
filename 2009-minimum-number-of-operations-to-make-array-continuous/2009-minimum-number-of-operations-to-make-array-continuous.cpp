class Solution {
public:
    vector<int>v;
    int findans(int first,int second,int n)
    {
        auto it=lower_bound(v.begin(),v.end(),first);
        auto itt =lower_bound(v.begin(),v.end(),second+1);
        if(itt==v.begin())
          return n;
        itt--;
        int left=0;
        left=it-v.begin();
        int right=0;
        right=itt-v.begin(); 
        return n-(right-left+1);
    }
    int minOperations(vector<int>& nums) {
        
        int l=nums.size()-1;
        int n=l+1;
        
        map<int,int>m;
        for(auto i:nums)
            if(m[i]==0){
                v.push_back(i);
                m[i]=1;
        }
        sort(v.begin(),v.end());
        int ans=INT_MAX;
        for(auto i:v)
        {
            ans=min(ans,findans(i,i+l,n));
            
            ans=min(ans,findans(i-l,i,n));
        }
        return ans;
    }
};