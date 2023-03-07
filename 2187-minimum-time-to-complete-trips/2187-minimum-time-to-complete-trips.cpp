class Solution {
public:
    long long  getval(vector<int>&v,long long  time)
    {
        long long  count=0;
        for(auto i:v)
            count+=time/i;
        return count;
    }
    long long  findans(vector<int>&t,long long  tot)
    {
        long long  low=1;
        long long  high=1e14;
        long long  final_ans=1e15;
        while(low<=high)
        {
                long long  mid=low+(high-low)/2;
            
            long long  val=getval(t,mid);
            if(val>=tot)
            {
                final_ans=min(final_ans,mid);
                high=mid-1;
            }
            else
            {
                low=mid+1;
            }
            
        }   
        return final_ans;
    }
    long long minimumTime(vector<int>& time, int totalTrips) {
        
        return findans(time ,totalTrips);
    }
};