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
    bool possibleBipartition(int n, vector<vector<int>>& v) {
        
        vector<vector<int>>arr(n+1);
        for(auto i:v)
        {
            arr[i[0]].push_back(i[1]);
            arr[i[1]].push_back(i[0]);
        }
        
        vector<int>col(n+1,-1);
        for(int i=1;i<=n;i++){
            if(col[i]==-1){
                if(findans(arr,i,col,0)==false)
                    return false;
            }
        }
        return true;
    }
};