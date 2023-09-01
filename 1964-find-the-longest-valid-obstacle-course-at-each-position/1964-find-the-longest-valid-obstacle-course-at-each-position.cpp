class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& v) {
        vector<int>temp; 
        temp.push_back(v[0]);
        vector<int>res(v.size(),0);
        res[0]=1;
        for(int i=1;i<v.size();i++){
            if(v[i]>=temp.back())
            {
                temp.push_back(v[i]); 
                res[i]=temp.size();
            }
            else
            { 
                auto it=upper_bound(temp.begin(),temp.end(),v[i]);
                int ind=it-temp.begin();
                temp[ind]=v[i]; 
                res[i]=ind+1;
            }
        }
        
        return res;
    }
};