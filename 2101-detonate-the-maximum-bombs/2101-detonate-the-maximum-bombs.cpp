class Solution {
public:
    
    int findans(vector<int>arr[],vector<int>&vis,int node)
    {
            vis[node]=1;
        int count=1;
        for(auto i:arr[node])
        {
            if(vis[i]==0)
            {
            count+=findans(arr,vis,i);
            }
        }
        return count;
    }
    int maximumDetonation(vector<vector<int>>& b) {
        
        
        int n=b.size();
        vector<int>arr[n];
        for(int i=0;i<n;i++)
        {
        for(int j=0;j<n;j++)
        {
            if(i==j)
                continue;
            long long  first=b[i][0]-b[j][0];
            long long second=b[i][1]-b[j][1]; 
           int rad=(b[i][2] );
            if(sqrt(first*first+second*second)<=(rad ))
            {
                arr[i].push_back(j); 
            }
        }
        }
        
            
            int ans=INT_MIN;
            for(int i=0;i<n;i++)
            {
                 
                    
                    vector<int>vis(n,0);
                        ans=max(ans,findans(arr,vis,i));
                 
            }
            return ans;
        
    }
};