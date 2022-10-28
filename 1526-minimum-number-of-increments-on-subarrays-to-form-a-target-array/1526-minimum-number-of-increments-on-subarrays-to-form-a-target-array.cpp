class Solution {
public:
    int minNumberOperations(vector<int>& v) {
        int  count=0;
        count+=v[0];
        int n=v.size();
        for(int i=1;i<n;i++)
        {
            int diff=v[i]-v[i-1];
            diff=max(diff,0);
            count+=diff;
        }
        return count;
    }
};