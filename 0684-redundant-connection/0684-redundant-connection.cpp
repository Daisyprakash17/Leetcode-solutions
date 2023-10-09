class Solution {
public:
    void findans(vector<vector<int>>&arr,int node,int& timer,vector<int>&low,vector<int>&desc,vector<pair<int,int>>&v,int par)
    {
     low[node]=desc[node]=timer++;
        for(auto i:arr[node])
        {
                if(i==par)
                    continue;
            if(desc[i]==-1){
            findans(arr,i,timer,low,desc,v,node);
            low[node]=min(low[node],low[i]);
            }else{
                low[node]=min(low[node],desc[i]);
            }
            if(low[node]==low[i])
                v.push_back({node,i});
        }
    }
    vector<int> findRedundantConnection(vector<vector<int>>& v) {
        int n=v.size();
        vector<vector<int>>arr(n+1);
        map<pair<int,int>,int>m;
        int in=1;
        for(auto i:v)
        {
            arr[i[0]].push_back(i[1]);
            arr[i[1]].push_back(i[0]);
            m[{i[0],i[1]}]=in++;
        } 
        vector<int>low(n+1,-1);
        vector<int>desc(n+1,-1);
        in=1;
        vector<pair<int,int>>temp;
        findans(arr,1,in,low,desc,temp,-1);
        
        int cur=-1;
        vector<int>ans;
        for(auto i:temp)
        { 
            if(m[{i.first,i.second}]>cur){
                cur=m[{i.first,i.second}];
                ans.clear();
                ans.push_back(i.first);
                ans.push_back(i.second);
            }else if(m[{i.second,i.first}]>cur)
            {
                cur=m[{i.second,i.first}];
                ans.clear();
                ans.push_back(i.second);
                ans.push_back(i.first);
            }
        }
        return ans;
    }
};