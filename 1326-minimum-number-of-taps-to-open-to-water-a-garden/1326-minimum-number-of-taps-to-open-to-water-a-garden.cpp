class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        map<int,vector<int>>v;
        for(int i=0;i<=n;i++)
        {
            int left=max(0,i-ranges[i]);
            int right=min(n,i+ranges[i]);
            
            v[left].push_back(right); 
        }
        int temp=0;
        int count=0;
        int flag=1;
        int i=0;
        while(temp<=n)
        {
          
            int newtemp=-1;
            for( i;i<=temp;i++)
            {
                for(auto j:v[i])
                    if(j>=newtemp)
                        newtemp=j;
            }
            if(newtemp>temp)
            {
                temp=newtemp;
                count++;
            }
            else
            { 
                break;
            }
        } 
        if(temp<n)
            return -1;
        else
            return count;
        
    }
};