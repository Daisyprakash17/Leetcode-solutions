class Solution {
public:
    int findans(vector<int>&v,int k,int n)
    {
        
        int i=0;
        int j=0; 
        int ans=-1;
        while(j<v.size())
        {
           int df=j-i+1;
            int ds=v[j]-v[i]+1;
            if((ds-df)<=k)
            { 
                j++; 
                
            ans=max(ans,df);
            }
            else
                i++;
        }
        return ans;
    }
    int longestEqualSubarray(vector<int>& v, int k) {
        map<int,vector<int>>m;
        for(int i=0;i<v.size();i++) 
                m[v[i]].push_back(i); 
        
        int ans=0;
        for(auto i:m)
        { 
            int val=findans(i.second,k,v.size()-1);
            ans=max(ans,val); 
        }
        return ans;
    }
};