class Solution {
public:
    int singleNumber(vector<int>& nums) {
        vector<int>temp(31,0);
        vector<int>temp2(32,0);
        for(auto i:nums)
            {
                if(i>=0)
                {
                    for(int j=0;j<31;j++)
                    {
                        long long one=1;
                        if((i&(one<<j))==(one<<j))
                            temp[j]++;
                    }
                }
            else
            {
                
                    long long val=abs(i);
                    for(int j=0;j<32;j++)
                    {
                        long long one=1;
                        if((val&(one<<j))==(one<<j))
                            temp2[j]++;
                    }
            }
        }
        long long  first=0;
        long long second=0;
        for(int j=0;j<31;j++)
        {
            long long one=1;
            if(temp[j]%3!=0)
                first+=(one<<j);
        }
        
        for(int j=0;j<32;j++)
        {
            long long one=1;
            if(temp2[j]%3!=0)
                second+=(one<<j);
        }
        if(first==0)
            return second*(-1);
        
        else
            return first;
    }
};