class Solution {
public:
    bool findval(vector<vector<int>>&v,int w){
        int n=v.size();
        int m=v[0].size();
        if(v[0][0]<w)
            return false;
        vector<vector<int>>vis(v.size(),vector<int>(v[0].size(),0));
        
        queue<pair<pair<int,int>,int>>q;
        q.push({{0,0},w});
        int flag=false;
        
        while(q.size()>0)
        {
            int i=q.front().first.first;
            int j=q.front().first.second;
            int tt=q.front().second;
            q.pop();
            if(i==(n-1) && j==(m-1)){
                flag=true;
                break;
            }
            if(vis[i][j]==1)
                continue ;
            vis[i][j]=1;
            if( (i-1)>=0  && v[i-1][j]>=w && vis[i-1][j]==0 && (tt+1)<v[i-1][j]){
                q.push({{i-1,j},tt+1});
            }
            if( (i+1)<n  && v[i+1][j]>=w && vis[i+1][j]==0 && (tt+1)<v[i+1][j] || ((i+1)==(n-1) && (j)==(m-1) && tt+1<=v[i+1][j])){
                q.push({{i+1,j},tt+1});
            }
            if((j-1)>=0  && v[i][j-1]>=w && vis[i][j-1]==0 && (tt+1)<v[i][j-1]){
                q.push({{i,j-1},tt+1});
            }
            if((j+1)<m  && v[i][j+1]>=w && vis[i][j+1]==0 && ((tt+1)<v[i][j+1]) || (i==(n-1) && (j+1)==(m-1) && tt+1<=v[i][j+1])){
                q.push({{i,j+1},tt+1});
            }
        }
            return flag;
    }
    int findans(vector<vector<int>>&v){
        
        int low=0;
        int high=1e9;
        int ans=-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            int  check=findval(v,mid);
            // cout<<mid<<" "<<check<<endl;
            if(check==true){
                ans=mid;
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return ans;
    }
    int maximumMinutes(vector<vector<int>>& v) {
            int n=v.size();
        int m=v[0].size();
        queue<pair<pair<int,int>,int>>q;
        vector<vector<int>>t(n,vector<int>(m,INT_MAX));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                    if(v[i][j]==1){
                            q.push({{i,j},0});
                    }
                    else if(v[i][j]==2)
                        t[i][j]=-1;
            }
        }
        while(q.size()>0){
            int i=q.front().first.first;
            int j=q.front().first.second;
            int d=q.front().second;
            q.pop();
            if(d>t[i][j])
                continue;
            
            t[i][j]=d;
            if((i-1)>=0 && t[i-1][j]>(d+1) && v[i-1][j]!=2)
                q.push({{i-1,j},d+1});
            if((i+1)<n && t[i+1][j]>(d+1) && v[i+1][j]!=2)
                q.push({{i+1,j},d+1});
            if((j-1)>=0 && t[i][j-1]>(d+1) && v[i][j-1]!=2)
                q.push({{i,j-1},d+1});
            if((j+1)<m && t[i][j+1]>(d+1) && v[i][j+1]!=2)
                q.push({{i,j+1},d+1});
        }
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<m;j++)
        //         cout<<t[i][j]<<" ";
        //     cout<<endl;
        // }
        return findans(t);
    }
};