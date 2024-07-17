class Solution {
public:
    
    int findmincities(int node,vector<vector<pair<int,int>>>&arr,int d,int n,vector<vector<int>>&edges){
        
        vector<int>dis(n,INT_MAX);
        
        // below is using dijkstra
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,node});
        dis[node]=0;
        while(pq.size()>0){
            pair<int,int>pvalue=pq.top();
            int curnode=pvalue.second;
            int curdis=pvalue.first;
            pq.pop();
            
            if(dis[curnode]>curdis){
                continue;
            }
            
            for(auto i:arr[curnode]){
                if(dis[i.first]>=curdis+i.second){
                    pq.push({curdis+i.second,i.first});
                        dis[i.first]=curdis+i.second;
                }
                
            }
        }
        
        
       
        
        int count=0;
        for(auto i:dis){
            if(i<=d)
                count++;
        }
        return count-1;
        
    }
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        
        vector<vector<pair<int,int>>>arr(n);
        for(auto i:edges)
        {
            arr[i[0]].push_back({i[1],i[2]});
            arr[i[1]].push_back({i[0],i[2]});
        }
        
        int minicities=INT_MAX;
        int ans;
        for(int i=0;i<n;i++){
            int res=findmincities(i,arr,distanceThreshold,n,edges);
            if(res<minicities){
                minicities=res;
                ans=i;
            }
            else if(res==minicities)
                ans=max(ans,i);
            cout<<i<<" "<<res<<endl;
        }
        cout<<endl;
        return ans;
    }
};