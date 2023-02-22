class Solution {
public:
    
    int solve(vector<int>v,int val)
    {
        int count=1;
        int cv=val;
        for(auto i:v)
        {
            
           
            if(i<=cv)
                cv-=i;
            else
            {
                cv=val;
                cv-=i;
                count++;
            }
        }
        return count;
    }
    
    int get_final_ans(vector<int>v,int d )
    {
        int final_ans=INT_MAX;
        int low=*max_element(v.begin(),v.end());
        int high=v.size()*500;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            int val=solve(v,mid);
             //if value is negative or less than days
            // means we have to increase the capacity
            if(val<=d)
                final_ans=min(final_ans,mid);
            
                if(val<=d)
                {
                    high=mid-1 ;
                }
                else
                    low=mid+1;
                    
             
        }
        return final_ans;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        
        return get_final_ans(weights,days);
        
    }
};