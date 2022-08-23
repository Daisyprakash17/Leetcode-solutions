class Solution {
public:
    void nextPermutation(vector<int>& v) {
        
        int flag=0; 
        
        int n=v.size();
        multiset<int>s;
        for(int i=n-1;i>=0;i--)
        {
            auto it=s.lower_bound(v[i]+1);
            if(it!=s.end())
            {
                int val=*it;
                s.erase(it);
                s.insert(v[i]);
                v[i]=val;
                
                for(int j=i+1;j<n;j++)
                {
                    v[j]=(*s.begin());
                    s.erase(s.begin());
                }
                flag=1;
                break;
            }
            else
            {
               s.insert(v[i]);
            }
        }
        if(flag==0)
            sort(v.begin(),v.end());
    }
};