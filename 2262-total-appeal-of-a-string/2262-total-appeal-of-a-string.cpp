class Solution {
public:
    long long appealSum(string s) {
        reverse(s.begin(),s.end());
        long long  ans=1;
        vector<int>temp(26,-1);
        temp[s[0]-'a']=0;
        
        for(int i=1;i<s.size();i++)
        {
            temp[s[i]-'a']=i;
            for(auto i:temp)
                ans+=i+1;
        }
        return ans;
    }
};