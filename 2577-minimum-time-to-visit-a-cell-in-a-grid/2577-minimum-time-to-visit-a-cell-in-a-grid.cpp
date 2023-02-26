class Solution {
public:
    void fillit(int i,int j,int temp,priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>&q,vector<vector<int>>&v,vector<vector<int>>&val)
    {
        if(temp+1<val[i][j] && temp+1>=v[i][j]){
                val[i][j]=temp+1;
                q.push({temp+1,{i,j}});
                }else if(temp<v[i][j])
                {
                    int t=v[i][j];
                    if(temp%2==v[i][j]%2) 
                        t++; 
                    val[i][j]=t;
                    q.push({t,{i,j}});
                }
    }
    int minimumTime(vector<vector<int>>& v) {
            // if i cannot even make a single move than it is not possible to
        // to move the bottm right cell 
        if(v[0][1]>1 && v[1][0]>1)
            return -1;
        
        
        int n=v.size();
        int m=v[0].size();
        vector<vector<int>>val(n,vector<int>(m,INT_MAX));
        val[0][0]=0;
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>q;
        q.push({0,{0,0}});
        while(q.size()>0)
        {
            int temp=q.top().first;
            int i=q.top().second.first;
            int j=q.top().second.second;
            q.pop();
            if(temp>val[i][j])
                continue; 
            if(i-1>=0)
                 fillit(i-1,j,temp,q,v,val);
            if(i+1<n)
                 fillit(i+1,j,temp,q,v,val);
            if(j-1>=0)
                 fillit(i,j-1,temp,q,v,val);
            
            if(j+1<m)
                 fillit(i,j+1,temp,q,v,val);
        }   
        return val[n-1][m-1];
    }
};