class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        
            int o=0;
        int e=0;
        long long int count=0;
        int sum=0;
        if(arr[0]%2==0)
            e++;
        else
        {
            count++;
            o++;
        }
        sum+=arr[0];
            for(int i=1;i<arr.size();i++)
            {
                sum+=arr[i];
                if(sum%2==1)
                {
                    count++;
                    count+=e;
                    o++;
                }
                else
                {
                    count+=o;
                    e++;
                }
                
                count=count%1000000007;
                
            }
        return count;
    }
};