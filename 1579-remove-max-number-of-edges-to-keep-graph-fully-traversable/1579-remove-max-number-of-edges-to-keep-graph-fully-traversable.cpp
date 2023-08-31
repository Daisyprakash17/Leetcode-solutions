class Solution {
public:
    int par[100005];
    int rank[100005];
    void makedsu(int n)
    {
        
        for(int i=0;i<=n;i++)
           {
            par[i]=i;
            rank[i]=1;   
        }
    }
    int getpar(int n)
    {
        if(par[n]==n)
            return n;
        // this is path compression
        return par[n]=getpar(par[n]);
    }
    void unionbyr(int a,int b)
    {
        if(getpar(a)==getpar(b))
            return ;
        int pa=getpar(a);
        int pb=getpar(b);
        if(rank[pa]>rank[pb])
        {
            par[pb]=pa;
        }
        else if(rank[pa]<rank[pb]){
            par[pa]=pb;
        }
        else{
            par[pb]=pa;
            rank[pa]++;
        }
    }
    int getres(vector<pair<int,int>>&v,int n){
        int count=0;
        for(auto i:v)
            if(getpar(i.first)!=getpar(i.second))
                unionbyr(i.first,i.second);
        else
            count++;
        set<int>s;
            for(int i=1;i<=n;i++)
                s.insert(getpar(i));
        
        
        if(s.size()==1)
            return count;
        return -1;
    }
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        map<int,vector<pair<int,int>>>v;
        for(auto i:edges)
            v[i[0]].push_back({i[1],i[2]});
        makedsu(n);
        int count=0;
        for(auto i:v[3])
            if(getpar(i.first)!=getpar(i.second))
            unionbyr(i.first,i.second);
        else
            count++;
        int first=getres(v[1],n);
          makedsu(n);
        for(auto i:v[3])
            unionbyr(i.first,i.second);
        int second=getres(v[2],n); 
        if(first!=-1 && second!=-1)
            return first+second+count;
        return -1;
    }
};