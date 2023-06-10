class Solution {
public:
    long long  checkval(long long n,int index,long long val)
    {
        long long sum=0;
        // left sum 
        long long left=0;
        if(val-1>=index)
        {
            long long re=val-(index+1);
            left+=(val*(val+1)/2)-(re*(re+1)/2); 
        }
        else
        {
            long long re=index+1-val;
            left+=(val*(val+1)/2)+re; 
        }
        
        // right
        long long right=0;
        if((n)-index<val)
        {
            long long re=val-(n-index);
            right+=(val*(val+1)/2)-(re*(re+1)/2);
             
        }
        else
        {
            int re=(n-index)-val;
            right+=(val*(val+1)/2)+re;
                
        }
         
        return left+right-val;
    }
    int findans(int n,int index,long long maxsum)
    {
        int low=1;
        int high=maxsum;
        int ans;
        while(high>=low)
        {
            int mid=low+(high-low)/2;
            long long tempval=checkval(n,index,mid); 
            if(tempval<=maxsum)
            {
                ans=mid;
                low=mid+1;
            }
            else
                high=mid-1;
        }
        return ans;
        
    }
    int maxValue(int n, int index, int maxSum) {
        return findans(n,index,maxSum);
    }
};