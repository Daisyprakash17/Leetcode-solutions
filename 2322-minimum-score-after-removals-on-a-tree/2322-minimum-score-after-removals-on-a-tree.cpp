class Solution {
public:
    map<int,int>xval;
    int in[1002];
    int out[1002];
    vector<int>v[1001];
    vector<int>values;
    void findans(int node ,int &t,int par)
    { 
            
          
        in[node] =t;
        t++;
        int val=values[node];
        for(auto i:v[node])
        {
                if(i!=par)
                {
                    findans(i,t,node);
                    val=val^xval[i];
                }
            }
        t++;
        out[node] =t;
         xval[node]=val; 
         
    }
    
    
    int minimumScore(vector<int>& nums, vector<vector<int>>& edges) {
        int n=nums.size();
         values=nums;
        
        
        
        for(auto i:edges)
        {
            v[i[0]].push_back(i[1]);
            v[i[1]].push_back(i[0]);
        }
          
        int time=1;
        findans(0,time,-1);
         
            
          
         
        int ans=INT_MAX;
          
        for(int i=1;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                     
                        int temp=xval[0];
                        vector<int>vv(3); 
                        if(in[i]<in[j] && out[i]>out[j] )
                        {
                            vv[1]=xval[i];
                            vv[0]=temp^vv[1];
                            vv[2]=xval[j];
                            vv[1]=vv[1]^vv[2];
                        }
                        else if(in[i]>in[j] && out[i]<out[j])
                        {
                            vv[1]=xval[j];
                            vv[0]=temp^vv[1];
                            vv[2]=xval[i];
                            vv[1]=vv[1]^vv[2];
                        }
                        else
                        {
                            vv[1]=xval[i];
                            vv[2]=xval[j]; 
                            temp=temp^vv[1];
                             temp=temp^vv[2];
                             vv[0]=temp;
                         }
                        sort(vv.begin(),vv.end());
                         
                        
                        ans=min(ans,vv[2]-vv[0]);
                     
                        
            }
        }
       
        return ans;
    }
};