class Solution {
public:
    int maxPoints(vector<vector<int>>& p) {
        
        int ans=0;
        // sort all the value to make sure x2-x1 of the slope will all >=0
        sort(p.begin(),p.end());
        int n=p.size();
        for(int i=0;i<n;i++)
        {
            // for each points calculating the slope and storing the
            // in form of pair {numrator,denomrator}
            map<pair<int,int>,int>m; 
            for(int j=0;j<n;j++)
            {
                if(i==j)  // continue the loop for same point
                    continue;
                
                
                // calculating the numrator and denomator
                int num=p[j][1]-p[i][1];
                int deno=p[j][0]-p[i][0];
                
                // taking the hcf of the value and dividing each with hcf so as to reduce 
                int hcf=__gcd(deno,num); 
                
                // if hcf is one makign hcf as 1 so as to deal with the edges cases
                if(hcf==0)
                    hcf=1;
                deno/=hcf;
                num/=hcf; 
                
                // increamenting the slope which is stored in for of pair {numm,demo}
                m[{num,deno}]++;
                
            }
            
            // checking the map for the maximun repetaive slope 
            for(auto i:m)
                ans=max(ans,i.second);
                
            
        }
        // return ans+1 so as to count the point itself 
        return ans+1;
    }
};