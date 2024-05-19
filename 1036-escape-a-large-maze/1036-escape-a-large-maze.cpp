class Solution {
public:
    int check(vector<vector<int>>&blocked,vector<int>point,pair<int,int>other){
        
        map<pair<int,int>,int>m;
        map<pair<int,int>,int>b;
        int sb=blocked.size()+2;
        for(auto i:blocked)
            b[{i[0],i[1]}]=1;
        int count=0;
        queue<pair<int,int>>q;
        q.push({point[0],point[1]});
        
        while(q.size() && count<165000){
            
            pair<int,int>p=q.front();
            q.pop();
            if(p.first<0 || p.first>=1e6 || p.second<0 || p.second>=1e6)
                continue;
            if(m[p]==1 || b[p]==1)
                continue;
            if(m[{point[0],point[1]+sb}]==1)
            return true;
            if(m[{point[0],point[1]-sb}]==1)
                return true;
            if(m[{point[0]+sb,point[1]}]==1)
                return true;
            if(m[{point[0]-sb,point[1]}]==1)
                return true;
            if(p==other)
                return true;
            count++;
            m[p]++;
            
                
            q.push({p.first+1,p.second});
            q.push({p.first-1,p.second});
            q.push({p.first,p.second+1});
            q.push({p.first,p.second-1});                
        }
        
        
        return false;
    }
    bool isEscapePossible(vector<vector<int>>& blocked, vector<int>& source, vector<int>& target) {
        int first=check(blocked,source,{target[0],target[1]});
        int second=check(blocked,target,{source[0],source[1]});
        if(first==1 && second==1)
            return true;
        return false;
    }
};