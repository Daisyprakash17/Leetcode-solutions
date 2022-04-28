class Solution {
public:
    bool check(vector<int>v)
    {
        vector<int>val;
        val=v;
        sort(val.begin(),val.end());
        for(int i=0;i<v.size();i++)
        {
            if(val[i]!=v[i])
                return false;
        }
        return true;
    }
    
    bool checkPossibility(vector<int>& v) {
        int n=v.size();
            int in=-1;
        for(int i=0;i<n-1;i++)
        {
            if(v[i]>v[i+1])
            {
                in=i;
                break;
            }
        }
        if(in==-1)
            return true; 
        vector<int>first=v;
        vector<int>second=v;
        first[in]=first[in+1];
        second[in+1]=second[in];
        
         if(check(first) || check(second))
             return true;
             else
        return false;
    }
};