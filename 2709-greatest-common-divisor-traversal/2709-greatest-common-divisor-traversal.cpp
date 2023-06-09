class Solution {
public:
    vector<int>par ;
    vector<int>rnk ; 
void makeset(int n)
{
    par.resize(n+1);
    rnk.resize(n+1); 
    for(int i=0;i<=n;i++)
    {
        par[i]=i;
        rnk[i]=0; 
    }
}
int findpar(int node)
{

    if(par[node]==node)
        return node; 
    return par[node]=findpar(par[node]);
}
void union_element(int u,int v)
{

    u=findpar(u);
    v=findpar(v);


    if(u==v)
    return ;  
    if(rnk[u]<rnk[v]){
        par[u]=v; 
    }else if(rnk[u]>rnk[v]){
        par[v]=u; 
    }else{
        par[v]=u;
        rnk[u]++;  
    } 
}
    vector<long long> factors(long long n) {
    vector<long long> factorization;
    for (long long d = 2; d * d <= n; d++) {
        while (n % d == 0) {
            factorization.push_back(d);
            n /= d;
        }
    }
    if (n > 1)
        factorization.push_back(n);
    return factorization;
}
    bool canTraverseAllPairs(vector<int>& nums) {
        
      if(nums.size()==1)
          return true;
        map<int,vector<int>>m;
        int flag=true;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==1)
                flag=false;
            vector<long long >temp=factors(nums[i]);
            for(auto j:temp)
                m[i].push_back(j);
        }
        if(!flag)
            return flag;
        makeset(1e5);
        set<int>fac;
        
        for(auto i:m)
        {
            fac.insert(i.second[0]);
            for(int j=1;j<i.second.size();j++) {
                fac.insert(i.second[j]);
                union_element(i.second[j],i.second[j-1]);  
            }   
        }
        
        set<int>s;
        for(auto i:fac)
            s.insert(findpar(i)); 
        if(s.size()==1)
            return true;
        else
            return false; 
    }
};