class Solution {
public:
    
    void filltemp(vector<int>arr[],int node,vector<int>&vis,vector<pair<int,int>>&temp)
    {
         
        int  count=0;
        int sum=0;
        vis[node]=1;
        for(auto i:arr[node])
        {
            if(vis[i]==0)
            { 
                filltemp(arr,i,vis,temp);
                count+=temp[i].first+1;
                sum+=temp[i].second+temp[i].first+1;
            }
        }
        temp[node]=make_pair(count,sum);
    }
    void fillans(vector<int>arr[],int node,vector<int>&vis,vector<pair<int,int>>&temp,vector<int>&ans,pair<int,int>val)
    {
                
        vis[node]=1; 
        if(node==0)
           {
            ans[node]=temp[node].second;
            val.first=temp[node].first;
            val.second=temp[node].second;
        }
        else
        {
            int dis=val.second -temp[node].second -(temp[node].first+1)+(vis.size()-(temp[node].first+1))+temp[node].second;
            int num=vis.size()-1;
            ans[node]=dis;
            val.first=num;
            val.second=dis;
        }
            
            for(auto i:arr[node])
                if(vis[i]==0)
                    fillans(arr,i,vis,temp,ans,val);
    }
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& e) {
        
        vector<int>arr[n];
        for(auto i:e)
        {
            arr[i[0]].push_back(i[1]);
            arr[i[1]].push_back(i[0]);
        }
        vector<int >ans(n,0);
        
        vector<pair<int,int>>temp(n);
        // temp vector is used to store the pair of (count,sum) of its child
        vector<int>vis(n,0);
        filltemp(arr,0,vis,temp);
        
       
        
        vector<int>dvis(n,0); 
            
        fillans(arr,0,dvis,temp,ans,make_pair(0,0));
        return ans;
    }
};