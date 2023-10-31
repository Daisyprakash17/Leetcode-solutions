class Solution {
public:
    static bool cmp(vector<int>&a,vector<int>&b){
        if(a[0]==b[0])
            return a[1]<b[1];
        return a[0]<b[0];
    }
    int findLongestChain(vector<vector<int>>& v) {
        sort(v.begin(),v.end(),cmp);
        int last=INT_MAX;
        int count=0;
            for(int i=v.size()-1;i>=0;i--){
                if(v[i][1]<last){
                    count++;
                    last=v[i][0];
                }
            }
        return count;
    }
    
};