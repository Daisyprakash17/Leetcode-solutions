class Solution {
public:
    void findans(vector<vector<int>>&v,vector<vector<int>>&vis,int & count,int i,int j,int temp){
        
        
        
        if(i<0 || j<0 || i>=v.size() || j>=v[0].size() || vis[i][j]==1 || v[i][j]!=1)
            return ;
        
        count++;
        vis[i][j]=1;
        v[i][j]=temp;
        findans(v,vis,count,i+1,j,temp);
        findans(v,vis,count,i,j+1,temp);
        findans(v,vis,count,i-1,j,temp);
        findans(v,vis,count,i,j-1,temp);
}
    int largestIsland(vector<vector<int>>& v) {
        
        
        
        int n=v.size();
        int m=v[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        
        int temp=2;
        int ans=0;
        map<int,int>mm;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vis[i][j]==0 && v[i][j]==1){
                   int count=0;
                    findans(v,vis,count,i,j,temp);
                    ans=max(ans,count);
                    mm[temp]=count;
                    temp++;
                }
            }
        }
        vector<vector<int>>ii={{0,1},{1,0},{-1,0},{0,-1}};
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(v[i][j]==0){
                    int temp=1;
                    set<int>s;
                    for(auto k:ii){
                        if(i+k[0]>=0 && i+k[0]<n && j+k[1]>=0 && j+k[1]<m ){
                           s.insert(v[i+k[0]][j+k[1]]);
                        }
                    }
                    for(auto i:s)
                        temp+=mm[i];
                    ans=max(ans,temp);
                }
            }
        }
        return ans;
    }
};