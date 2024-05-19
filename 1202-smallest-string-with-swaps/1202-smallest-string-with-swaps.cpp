class Solution {
public:
    void findstring(vector<vector<int>>&arr,vector<int>&vis,int node,string &temp,vector<int>&ind,string & s){
        
        vis[node]=1;
        temp+=s[node];
        ind.push_back(node);
        for(auto i:arr[node]){
            if(vis[i]==0)
                findstring(arr,vis,i,temp,ind,s);
        }
    }
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int n=s.size();
        
        vector<vector<int>>arr(n);
        for(auto i:pairs){
            arr[i[0]].push_back(i[1]);
            arr[i[1]].push_back(i[0]);
        }
        
        
        vector<int>vis(n,0);
        for(int i=0;i<n;i++){
            if(vis[i]==0){
                string temp;
                vector<int>ind;
                findstring(arr,vis,i,temp,ind,s);
                sort(temp.begin(),temp.end());
                sort(ind.begin(),ind.end());
                for(int j=0;j<ind.size();j++){
                    s[ind[j]]=temp[j];
                }
            }
            
        }
        return s;
    }
};