class Solution {
public:
    int maxi=-1;
    void  findans(vector<int>&v,int i,int n,int num)
    {
        
         
        if(i>=n)
        {
             int count=0;
            for(int i=0;i<30;i++)
            {
                if((num&(1<<i))==(1<<i))
                    count++;
            }
            maxi=max(maxi,count);
            return ;
        }
        if((num&v[i])>0)
        {
            // if any bit is same
             findans(v,i+1,n,num);
        }
        else
        {
            // if no bit is same
             findans(v,i+1,n,num);
            findans(v,i+1,n,(num|v[i]));
            
        }
        
    }
        
    int maxLength(vector<string>& arr) {
        
        
        vector<int>v;
        for(auto i:arr)
        {
            
                sort(i.begin(),i.end());
            int flag=0;
            for(int j=1;j<i.size();j++)
            {
                if(i[j]==i[j-1])
                {
                    flag=1;
                    break;
                }
            }
            if(flag==1)
                continue;
            
            int val=0;
            
            for(auto j:i)
            {
                val+=(1<<(j-'a'));
            }
            v.push_back(val);
         }
        
        findans(v,0,v.size(),0);
        return maxi;
        
    }
};