class Solution {
public:
    map<int ,bool>m;
    bool  findans(int cur,int maxi,int total)
    {
        if(total<=0)
            return false;  
         if(m.find(cur)!=m.end())
             return m[cur];
        for(int i=1;i<=maxi;i++)
        {
            if((cur&(1<<i))==(1<<i))
                continue;
            int newcur=cur|(1<<i);
            if(findans(newcur,maxi,total-i)==false)
            { 
                m[cur]=true;
                return true;
            } 
        }
               m[cur]=false;
                return false;
        
    }
    bool canIWin(int  maxi, int total) {
        
        if(maxi>=total)
            return true;
        if(maxi*(maxi+1)/2<total)
            return false;
         
        return findans(0,maxi,total);
    }
};