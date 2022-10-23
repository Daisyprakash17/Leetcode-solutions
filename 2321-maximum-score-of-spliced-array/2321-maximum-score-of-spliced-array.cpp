class Solution {
public:
    int findmax(vector<int>&v)
    {
        int maxi=0;
        int sum=0;
        
        for(int i=0;i<v.size();i++)
        {
            sum+=v[i];
            if(sum<0)
                sum=0;
            
            maxi=max(maxi,sum);
        }
        return maxi;
    }
    int maximumsSplicedArray(vector<int>& a, vector<int>& b) {
        int ans1=0;
        int ans2=0;
        int n=a.size();
        for(int i=0;i<n;i++)
        {
            ans1+=a[i];
            ans2+=b[i]; 
            int temp=a[i];
            a[i]-=b[i];
            b[i]-=temp;
        }
        
         
        return max(ans1+findmax(b),ans2+findmax(a));
    }
};