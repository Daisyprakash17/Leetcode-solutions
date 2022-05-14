class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        
            int o=0;
        int e=0;
        long long int count=0;
        if(arr[0]%2==0)
            e++;
        else
        {
            count++;
            o++;
        }
            for(int i=1;i<arr.size();i++)
            {
                arr[i]+=arr[i-1];
                if(arr[i]%2==1)
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