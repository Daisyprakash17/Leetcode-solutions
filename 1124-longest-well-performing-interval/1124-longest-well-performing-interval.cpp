class Solution {
public:
    int longestWPI(vector<int>& v) {
         
        for(int i=0;i<v.size();i++)
        {
            if(v[i]>8)
                v[i]=1;
            else
                v[i]=-1; 
        }  
        int ans=0;
        int sum=0;
        map<int,int>m;
        for(int i=0;i<v.size();i++)
        {
                sum+=v[i];
            if(sum>0)
            {
                ans=i+1;
            }
            else{ 
                if(m.find(sum-1)!=m.end())
                { 
                    ans=max(ans,i-m[sum-1]);
                }
            }
            m.insert({sum,i});
        }
        return ans;
        
        
    }
};