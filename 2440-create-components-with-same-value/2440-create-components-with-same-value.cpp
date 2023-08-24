class Solution {
public:
    int findans(vector<vector<int>>&v,vector<int>&vis,int& count,int node,int sum ,vector<int>&nums)
    {
        vis[node]=1;
        int cursum=nums[node];
        for(auto i:v[node])
        {
            if(vis[i]==1)
                continue;
            int temp=findans(v,vis,count,i,sum,nums);
            if(temp!=-1)
                cursum+=temp;
            else{
                vis[node]=0;
                return -1;
            }
        }
        if(cursum==sum)
        {
            count++;
            cursum=0;
        }
        else if(cursum>sum)
            cursum=-1;
        vis[node]=0;
        return cursum;
    }
    int componentValue(vector<int>& nums, vector<vector<int>>& edges) {
        int sum=0;
        int n=nums.size();
        for(auto i:nums)
            sum+=i;
        vector<vector<int>>v(n);
        for(auto i:edges)
        {
            v[i[0]].push_back(i[1]);
            v[i[1]].push_back(i[0]);
        }
        vector<int>vis(n,0);
        int ans=0;
        int count=0;
        findans(v,vis,count,0,6,nums);
         for(int i=1;i<=sqrt(sum);i++)
        {
            if(sum%i==0)
            { 
                 count=0;  
                if(findans(v,vis,count,0,i,nums)==0)
                    ans=max(ans,count-1);
                 count=0;
                if(findans(v,vis,count,0,sum/i,nums)==0)
                    ans=max(ans,count-1);
             }
        }
        return ans;
        
    }
};