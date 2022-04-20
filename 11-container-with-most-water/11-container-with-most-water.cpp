class Solution {
public:
    int maxArea(vector<int>& v) {
        int ans=0;
        int i=0;
        int j=v.size()-1;
        
        while(i<j)
        {
            ans=max(ans,min(v[i],v[j])*(j-i));
            if(v[i]<v[j])
                i++;
            else
                j--;
        }
        return ans;
    }
};