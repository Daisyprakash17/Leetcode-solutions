class Solution {
public: 
    void findans(vector<int>&vis,int &ans,int count)
    {
        
        if(count==vis.size())
        { 
            ans++; 
            return ;
        }
        for(int i=0;i<vis.size();i++)
        {
            if(vis[i]==0 && ((i+1)%(count+1)==0 || (count+1)%(i+1)==0))
            {
                vis[i]=1; 
                findans(vis,ans,count+1);
                vis[i]=0; 
            }
        }
    }
    int countArrangement(int n) {
       
        vector<int>vis(n,0); // 0 denote that element is available
         int ans=0;
        int count=0;
        findans(vis,ans,count);
        return ans;
    }
};