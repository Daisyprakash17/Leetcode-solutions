class Solution {
public:
    long long  getval(vector<int>v,int mid)
    {
          long long count=0;
            for(auto i:v)
            {
                count+=i/mid;
                if(i%mid!=0)
                    count++;
            }
        return count;
        
    }
    int getans(vector<int>v,int t)
    {
        int n=v.size();
        int low=1;
        int high=v[n-1];
        int final_ans=INT_MAX;
        while(low<=high)
        {
                int mid=low+(high-low)/2;
            long long  count=getval(v,mid);
            if(count<=t)
            {
                final_ans=min(final_ans,mid);
                     high=mid-1;
            }
            else 
                low=mid+1;
        }
        return final_ans;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        sort(piles.begin(),piles.end());
        return getans(piles,h);
    }
};