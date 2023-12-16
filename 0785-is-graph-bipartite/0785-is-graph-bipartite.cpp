class Solution {
public:
    int findans(vector<vector<int>>&arr,int node,vector<int>&col,int c){
        col[node]=c;
        
        for(auto i:arr[node]){
            if(col[i]==-1){
               if(findans(arr,i,col,(c+1)%2)==false)
                    return false;
            }else if(col[i]==col[node])
                return false;
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& v) {
        int n=v.size();
        vector<vector<int>>arr(n);
        for(int i=0;i<n;i++){
                for(auto j:v[i])
                    arr[i].push_back(j);
        }
        
        vector<int>col(n,-1);
        for(int i=0;i<n;i++){
            if(col[i]==-1){
                if(findans(arr,i,col,0)==false)
                    return false;
            }
        }
        return true;
    }
};