class Solution {
public:
    void findans(vector<vector<int>>&arr,int node,vector<int>&vis,vector<int>&dvis)
    {
        vis[node]=1;
        dvis[node]=1; 
        for(auto i:arr[node])
        {
            if(vis[i]==0)
                findans(arr,i,vis,dvis);
        }
    }
    int check(vector<int>&v,map<pair<int,int>,int>&m)
    { 
        int n=v.size();
        int flag=1;
        for(int i=0;i<n;i++)
        {
            if(v[i]==0)
                continue;
            for(int j=i+1;j<n;j++)
                if(v[j]==1)
                { 
                 if(!((m[{i,j}]==1 || m[{j,i}]==1)))
                     flag=0;
                } 
            v[i]=0;
        }
      
        return flag;
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>>arr(n);
        map<pair<int,int>,int>m;
        for(auto i:edges)
        {
            arr[i[0]].push_back(i[1]);
            arr[i[1]].push_back(i[0]);
            m[{i[0],i[1]}]=1;
        }
        
        vector<int>vis(n,0),dvis(n,0);
        int count=0;
        for(int i=0;i<n;i++)
        {
            if(vis[i]==0)
            {
                findans(arr,i,vis,dvis);
                if(check(dvis,m)==true)
                    count++;
            }
        }
        return count;
        
    }
};