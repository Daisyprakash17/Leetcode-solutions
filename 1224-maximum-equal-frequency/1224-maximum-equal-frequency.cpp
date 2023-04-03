class Solution {
public:
    int maxEqualFreq(vector<int>& nums) {
        int n=nums.size();
        vector<set<int>>v(n+1);
        set<int>s; 
        map<int,int>m;
        
        int ans=1;
        for(int i=0;i<n;i++)
        {
            int val=nums[i]; 
            if(v[m[val]].size()==1)
            {
                v[m[val]].erase(val);
                s.erase(m[val]); 
            }
            else if(v[m[val]].size()>1)
            {
                v[m[val]].erase(val); 
            }
            m[val]++;
            v[m[val]].insert(val); 
            s.insert(m[val]);
           if(s.size()==1)
           {
               int first=*s.begin();
               if(first==1  || v[first].size()==1)
                   ans=i+1;
           }
            else if(s.size()==2)
            { 
                auto it=s.begin();
                int first=*it;
                it++;
                int second=*it; 
                 
                if(first==1 && v[first].size()==1)
                {
                    ans=i+1; 
                }
                if(second<first)
                swap(first,second); 
                if(second-first==1 && v[second].size()==1)
                    ans=i+1;
            }
        }
        return ans;
    }
};