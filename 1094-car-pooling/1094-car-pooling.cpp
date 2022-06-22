class Solution {
public:
   static bool cmp(vector<int >&a,vector<int>&b)
    {
        return a[1]<b[1];
    }
    bool carPooling(vector<vector<int>>& v, int c) {
         
        int sum=0;
        sort(v.begin(),v.end(),cmp);
         
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
        
        for(auto i:v)
        {
            
            while(q.size()>0 && q.top().first<=i[1])
            {
                sum-=q.top().second;
                q.pop();
            }
            if(sum+i[0]>c)
            {
                return false;
            }
            sum+=i[0];
            q.push({i[2],i[0]});
        }
        return true;
    }
};