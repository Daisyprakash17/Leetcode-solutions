class Solution {
public:
    int lengthOfLIS(vector<int>& v) {
        vector<int>temp;
        int ans=1;
        temp.push_back(v[0]);
        vector<int>res(v.size(),0);
        res[0]=1;
        for(int i=1;i<v.size();i++){
            if(v[i]>temp.back())
            {
                temp.push_back(v[i]);
                ans=temp.size();
                res[i]=ans;
            }
            else
            { 
                auto it=lower_bound(temp.begin(),temp.end(),v[i]);
                int ind=it-temp.begin();
                temp[ind]=v[i]; 
                ans=max(ans,ind+1); 
                res[i]=ind+1;
            }
        }
        
        return ans;
        
    }
};