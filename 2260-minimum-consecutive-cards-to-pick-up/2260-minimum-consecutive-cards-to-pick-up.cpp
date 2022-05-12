class Solution {
public:
    int minimumCardPickup(vector<int>& v) {
        map<int,int>m;
        
            int ans=INT_MAX;
        for(int i=0;i<v.size();i++)
        {
            int val=v[i];
            if(m[val]!=0) 
                ans=min(ans,(i+1)-m[val]);
                m[val]=i+1;
        }
        
        if(ans==INT_MAX)
            return -1;
        else
            return ans+1;
    }
    
};