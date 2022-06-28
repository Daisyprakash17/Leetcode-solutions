class Solution {
public:
    int minDeletions(string s) {
        vector<int>v(26,0);
        for(auto i:s)
            v[i-'a']++;
        sort(v.begin(),v.end());
        
        int count=0;
        
        for(int i=24;i>=0;i--)
        {
            if(v[i]>=v[i+1] && v[i]>0)
            {
                if(v[i+1]==0)
                {
                    count+=v[i];
                    v[i]=0;
                }
                else{
                count+=v[i]-v[i+1]+1;
                v[i]=v[i+1]-1;
            }
            }
        }
        return count;
        
    }
};