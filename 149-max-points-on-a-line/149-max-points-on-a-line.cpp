class Solution {
public:
    int maxPoints(vector<vector<int>>& p) {
        
        int ans=0;
        sort(p.begin(),p.end());
        int n=p.size();
        for(int i=0;i<n;i++)
        {
            
            map<pair<int,int>,int>m; 
            for(int j=0;j<n;j++)
            {
                if(i==j)
                    continue;
                int first=p[j][1]-p[i][1];
                int second=p[j][0]-p[i][0];
                int hcf=__gcd(first,second); 
                if(hcf==0)
                    hcf=1;
                first/=hcf;
                second/=hcf; 
                m[{first,second}]++;
                
            }
            for(auto i:m)
                ans=max(ans,i.second);
                
            
        }
        return ans+1;
    }
};