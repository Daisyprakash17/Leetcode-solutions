class Solution {
public:
   
    bool checkSubarraySum(vector<int>& nums, int k) {
        
        int n=nums.size();
        if(n==1)
            return false;
        map<int,int>m;
        int sum=0;  
        for(int i=0;i<n;i++)
        {
             
            sum+=nums[i];
            int res=sum%k;
            if(res==0 && i>=1)
                return true;
             if(m.find(res)!=m.end() &&  (i-m[res])>=2)
                return true;
            if(m.find(res)==m.end())
            m[res]=i ;
        }
        
        return false;
     
    }
};