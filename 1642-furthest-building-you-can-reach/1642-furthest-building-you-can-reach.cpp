class Solution {
public:
    bool getval(vector<int>&v,int mid,int b,int l)
    {
         priority_queue<int>q;
        long long int sum=0;
        for(int i=1;i<mid;i++)
            if(v[i]-v[i-1]>0)
            {
                sum+=v[i]-v[i-1];
                q.push(v[i]-v[i-1]);
            }
        else
            q.push(0);
         if(l>=q.size() || sum<=b)
            return true;
        while( q.size()>0 && l>0)
        {
            sum-=q.top();
             q.pop(); 
                l--; 
            
        } 
        return (sum<=b);
    }
    int findans(vector<int>&v,int b,int l)
    {
        
        int ans=-1;
        int low=1;
        int high=v.size();
        while(low<=high)
        {
            
            int mid=low+(high-low)/2;
            
            bool val=getval(v,mid,b,l);
             if(val)
            {
                low=mid+1;
                ans=max(ans,mid );
            }
            else 
                high=mid-1;
        }
        return ans;
        
    }
    int furthestBuilding(vector<int>& v, int b, int l) {
        return findans(v,b,l)-1;
    }
};