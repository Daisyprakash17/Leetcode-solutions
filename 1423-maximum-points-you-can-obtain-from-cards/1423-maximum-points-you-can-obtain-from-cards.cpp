class Solution {
public:
    int maxScore(vector<int>& v, int k) {
        int n=v.size();
        if(n==k)
        {
            int sum=0;
            for(auto i:v)
                sum+=i;
            return sum;
        }
        int ma=-1;
        int sum=0;
        for(int i=n-1;i>=n-k;i--)
            sum+=v[i]; 
        
         ma=sum;
        int i=0;
        int j=n-k;
        while(j<n)
        {
            sum-=v[j];
            sum+=v[i];
            i++;
            j++;
            ma=max(ma,sum);
        }
        return ma;
    }
};