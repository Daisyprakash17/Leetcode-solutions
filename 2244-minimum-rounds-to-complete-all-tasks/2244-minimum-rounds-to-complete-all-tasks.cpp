class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        map<int,int>m;
        for(auto i:tasks)
            m[i]++;
        
        int ans=0;
        for(auto i:m)
            if(i.second==1)
                return -1;
        else
        {
            int first =i.second%3;
            int second=i.second/3;
            if(first==0   )
                ans+=second; 
            else
                ans+=second+1; 
                
        }
        return ans;
    }
};