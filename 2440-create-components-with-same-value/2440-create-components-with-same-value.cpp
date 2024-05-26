class Solution {
public:
    int getans(vector<vector<int>>&arr,int node,vector<int>&nums,bool & flag,int sum,vector<int>&vis){
        
        
        vis[node]=1;
        int tempsum=nums[node];
        for(auto i:arr[node]){
            if(vis[i]==0){
                
               tempsum+=getans(arr,i,nums,flag,sum,vis);
            }
        }
        if(tempsum==sum)
            tempsum=0;
        
        if(tempsum>sum)
            flag=false;
        return tempsum;
    }
    int findans(vector<vector<int>>&arr,int n,vector<int>&nums){
                
        int sum=0;
        for(auto i:nums)
            sum+=i;
       int ans=0;
        for(int i=2;i<=sum;i++){
            if(sum%i==0){
                vector<int>vis(n,0);
                bool flag=true;
                getans(arr,0,nums,flag,sum/i,vis);
                if(flag)
                    ans=max(ans,i-1);
            }
        }
        return ans;
    }
    int componentValue(vector<int>& nums, vector<vector<int>>& edges) {
        
        int n=nums.size();
        vector<vector<int>>arr(n);
        for(auto i:edges){
            arr[i[0]].push_back(i[1]);
            arr[i[1]].push_back(i[0]);
        }
        return findans(arr,n,nums);
    }
};