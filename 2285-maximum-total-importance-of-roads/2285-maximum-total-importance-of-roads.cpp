class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<vector<int>>arr(n);
        for(auto i:roads)
        {
            arr[i[0]].push_back(i[1]);
            arr[i[1]].push_back(i[0]);
        }
        vector<long long>v;
        for(auto i:arr)
            v.push_back(i.size());
        sort(v.rbegin(),v.rend());
        long long ans=0;
        long long temp=n;
        for(auto i:v){
            ans+=(i*temp);
            temp--;
        }
        return ans;
    }
};