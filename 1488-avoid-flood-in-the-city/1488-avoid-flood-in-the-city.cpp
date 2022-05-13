class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        
        map<int,int>zero;
        // -1 denote all lakes are emply
        map<int,int >ava;
        
        set<int>s;
        int n=rains.size();
        for(int i=0;i<n;i++)
        {
            
            int val=rains[i];
            if(val==0)
            {
                s.insert(i);
            }
            else if(val>0)
            {
                if(ava[val]==0)
                {
                    ava[val]=i+1;
                }
                else
                {
                    auto it=s.lower_bound(ava[val]-1);
                    if(it!=s.end()  )
                    {
                        ava[val]=i+1;
                        zero[*it]=val;
                        s.erase(it);
                    }
                    else
                    {
                        vector<int>temp;
                        return temp;
                    }
                }
            }
        }
        for(int i=0;i<n;i++)
        {
                if(rains[i]>0)
                    rains[i]=-1;
            else
            {
                if(zero[i]>0)
                    rains[i]=zero[i];
                else
                    rains[i]=1;
            }
        }
        return rains;
        
        
         
         
        
    }
};