class Solution {
public:
    pair<long long ,long long > findans(vector<int>first,vector<int>second)
    {
         
        sort(first.begin(),first.end());
        sort(second.begin(),second.end()); 
        long long  sum1=0;
        long long  sum2=0;
        int n=first.size();
        for(int i=0;i<n;i++)
        {
            if(first[i]>=second[i])
                sum1+=first[i]-second[i];
            
            if(second[i]>first[i])
                sum2+=second[i]-first[i];
        }
        return {sum1,sum2};
    }
    long long makeSimilar(vector<int>& nums, vector<int>& target) {
        vector<int>efirst,esecond;
        vector<int>ofirst,osecond;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            if(nums[i]%2==0)
                efirst.push_back(nums[i]);
            else
                ofirst.push_back(nums[i]);
            
            if(target[i]%2==0)
                esecond.push_back(target[i]);
            else
                osecond.push_back(target[i]);
        }
        
         pair<long long ,long long > ff=findans(efirst,esecond);
        pair<long long ,long long > ss=findans(ofirst,osecond);
          long long  ans=0;
        ans+=min(ff.first,ff.second)/2;
        ans+=min(ss.first,ss.second)/2;
        ans+=abs(ff.first-ff.second)/2;
        return ans;
    }
};