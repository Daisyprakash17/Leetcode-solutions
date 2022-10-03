class Solution {
public:
    int minCost(string s, vector<int>& t) {
        
        int time=0;
        int sum=0;
        int ma;
        sum=t[0];
        ma=t[0];
        
        for(int i=1;i<s.size();i++)
        {
            if(s[i]==s[i-1])
            {
                sum+=t[i];
                ma=max(ma,t[i]);
            }
            else
            {
                time+=sum-ma;
                sum=t[i];
                ma=t[i];
            }
        }
        time+=sum-ma;
        return time;
    }
};