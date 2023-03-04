class Solution {
public:
    long long countSubarrays(vector<int>& v, int minK, int maxK) {
        long long ans=0;
        
        vector<int>mi,ma;
        vector<int>right;
        for(int i=0;i<v.size();i++)
        {
                if(v[i]==minK)
                    mi.push_back(i);
                  if(v[i]==maxK)
                    ma.push_back(i);
                  if(v[i]<minK  || v[i]>maxK)
                    right.push_back(i);
        }
        
        right.push_back(v.size());
        for(int i=0;i<v.size();i++)
        {
            int mini=-1;
            int maxi=-1;
            int ri=-1;
            auto it=lower_bound(mi.begin(),mi.end(),i);
            if(it!=mi.end())
                mini=*it;
            it=lower_bound(ma.begin(),ma.end(),i);
            if(it!=ma.end())
                maxi=*it ;
            it=lower_bound(right.begin(),right.end(),i) ;
            ri=*it;
            if(maxi==-1 || mini==-1)
                break;
            if(ri>mini && ri>maxi)
                ans+=ri-max(mini,maxi);
        }
        return ans ;
    }
};