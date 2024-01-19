class Solution {
public:
    map<int,int>m;
    int fillmap(vector<vector<int>>&arr,map<int,set<int>>&s,int node,vector<int>&vis){
        
        int sum=0;
        vis[node]=1;
        for(auto i:arr[node]){
                if(vis[i]==0){
                    if(s[node].find(i)!=s[node].end())
                        sum++;
                    sum+=fillmap(arr,s,i,vis);
                }
        }
        return m[node]=sum;
    }
    void findans(vector<vector<int>>&arr,map<int,set<int>>&s,vector<int>&vis,int node,int& ans,int sum,int par,int k){
        vis[node]=1;
        int temp;
        temp=sum+m[node];
        if(temp>=k)
            ans++;
        for(auto i:arr[node]){
            if(vis[i]==0){
                int minus=0;
                if(s[node].find(i)!=s[node].end())
                    minus--;
                if(s[i].find(node)!=s[i].end())
                    minus++;
                findans(arr,s,vis,i,ans,temp-m[i]+minus,node,k);
            }
        }
        
    }
    int rootCount(vector<vector<int>>& edges, vector<vector<int>>& guesses, int k) {
        int n=edges.size()+1;
        vector<vector<int>>arr(n);
        
        for(auto i:edges){
            arr[i[0]].push_back(i[1]);
            arr[i[1]].push_back(i[0]);
        }
        
        map<int,set<int>>s;
        for(auto i:guesses)
            s[i[0]].insert(i[1]);
        vector<int>vis(n,0);
        fillmap(arr,s,0,vis);

        
        int ans=0;
        vector<int>dvis(n,0);
        findans(arr,s,dvis,0,ans,0,-1,k);
        return ans;
    }
};