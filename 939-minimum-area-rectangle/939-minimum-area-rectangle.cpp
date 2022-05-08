class Solution {
public:
    int minAreaRect(vector<vector<int>>& v) {
        
        int ans=INT_MAX;
        map<pair<int,int>,int>m; 
        for(auto i:v)
            m[{i[0],i[1]}]++;
        
       
        int n=v.size();
        for(int k=0;k<n;k++)
        {
            for(int l=k+1;l<n;l++)
            {
                int x1,x2,y1,y2;
                x1=v[k][0];
                y1=v[l][1];
                x2=v[l][0];
                y2=v[k][1];
                if(m[{x1,y1}] && m[{x2,y2}]  && x1!=x2 && y1!=y2)
                    ans=min(abs(x1 - x2)*abs(y1 - y2),ans);
            }
        }   
        if(ans==INT_MAX)
            return 0;
        else
            return ans;
    }
};