class Solution {
public:
    int root;
    vector<vector<int>>res;
    void findcycle(vector<vector<int>>&arr,int node,int& time,vector<int>&dvis,vector<int>&low,vector<int>&desc){
        dvis[node]=1;
        low[node]=desc[node]=time;
        time++;
        for(auto i:arr[node]){
            if(desc[i]==0){
                findcycle(arr,i,time,dvis,low,desc);
                if(low[i]<=low[node])
                {
                    low[node]=low[i];
                    res.push_back({node,i});
                    
                    }
            }
            else if(dvis[i]==1){
                low[node]=low[i];
                res.push_back({node,i});
            }
        }
        dvis[node]=0;
    }
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
            
        int n=edges.size();
        vector<vector<int>>v(n+1);
        
        map<vector<int>,int>m;
        for(auto i:edges)
            v[i[0]].push_back(i[1]);
        
        for(int i=0;i<n;i++)
            m[edges[i]]=i;
        
        vector<int>dvis(n+1,0);
        vector<int>low(n+1,0);
        vector<int>desc(n+1,0);
        int time=1;
        for(int i=1;i<=n;i++){
                if(desc[i]==0){
                  findcycle(v,i,time,dvis,low,desc);  
                }
        }
        vector<int>ans;
        int mi=INT_MIN;
            map<int,vector<int>>child;
            for(auto i:edges){
                child[i[1]].push_back(i[0]);
                if(child[i[1]].size()==2)
                    {
                        cout<<i[1]<<" have to parent"<<endl;
                        for(auto tt:res){
                            
                            if(tt[0]==child[i[1]][0] && tt[1]==i[1])
                                return {child[i[1]][0],i[1]};
                        }
                    return {i[0],i[1]};
                
                    }
                    
            }
        for(auto i:res)
            if(m[i]>mi){
                mi=m[i];
                ans=i;
            }
        return ans;
        
    }
};