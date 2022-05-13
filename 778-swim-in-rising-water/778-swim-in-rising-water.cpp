class Solution {
public:
    int swimInWater(vector<vector<int>>& v) {
        int n;
        n=v.size();
        vector<vector<int>>val(n,vector<int>(n,INT_MAX));
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>q;
        val[0][0]=0;
        q.push({0,{0,0}});
        
        
        while(q.size()>0)
        {
            auto it=q.top();
            q.pop();
            int curval=it.first;
            int i=it.second.first;
            int j=it.second.second;
             if(i+1<n && val[i+1][j]>max(v[i][j],v[i+1][j]))
            {
                val[i+1][j]=max(v[i][j],v[i+1][j]);
                v[i+1][j]=val[i+1][j];
                q.push({val[i+1][j],{i+1,j}});
            }
            
             if(j+1<n && val[i][j+1]>max(v[i][j],v[i][j+1]))
            {
                val[i][j+1]=max(v[i][j],v[i][j+1]);
                 
                v[i][j+1]=val[i][j+1];
                q.push({val[i][j+1],{i,j+1}});
            }
            
            
            
            if(i-1>=0 && val[i-1][j]>max(v[i][j],v[i-1][j]))
            {
                val[i-1][j]=max(v[i][j],v[i-1][j]);
                v[i-1][j]=val[i-1][j];
                q.push({val[i-1][j],{i-1,j}});
            }
            
             if(j-1>=0 && val[i][j-1]>max(v[i][j],v[i][j-1]))
            {
                val[i][j-1]=max(v[i][j],v[i][j-1]);
                v[i][j-1]=val[i][j-1];
                q.push({val[i][j-1],{i,j-1}});
            }
            
             
            
        }
       
        return val[n-1][n-1];
        
    }
};