class Solution {
public: 
    int getval(int val)
    {
        if(val%2==1)
            return val-1;
        return val;
    }
    bool  check(int a,int b)
    {
        if(a>b)
            swap(a,b);
        if(a%2==0 && b%2==1 && a+1==b)
            return true;
            return false;
    }
    int minSwapsCouples(vector<int>& v) {
          
        int j=1;
        map<int,vector<int>>e;
        for(int i=0;i<v.size();i+=2)
        {
            if(check(v[i],v[i+1])==false)
            {
                e[getval(v[i])].push_back(j);
                e[getval(v[i+1])].push_back(j);
                j++;
            }
        } 
        map<int,vector<int>>m; 
        for(auto i:e)
        { 
            m[i.second[0]].push_back(i.second[1]);
            m[i.second[1]].push_back(i.second[0]); 
        }       

        int count=0;
        vector<int>vis(j+1,0); 

        
        for(int i=1;i<=j;i++)
        {
            if(vis[i]==0)
            {
                queue<int>q;
                q.push(i);
                vis[i]=1;
                int temp=0;
                while(q.size()>0)
                {
                    int cell=q.front();
                    q.pop(); 
                    temp++;
                    for(auto t:m[cell])
                    {
                        if(vis[t]==0)
                        {
                            vis[t]=1;
                            q.push(t);
                        }
                    }
                }
                count+=temp-1;
            }
        }
        return count;
    }
};