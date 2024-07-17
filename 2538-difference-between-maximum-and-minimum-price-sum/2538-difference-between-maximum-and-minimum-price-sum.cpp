class Solution {
public:
    map<int,int>maxSum;
    int fillValues(int node,vector<vector<int>>&arr,vector<int>&prices,int par){
        
        int maxsum=0;
        for(auto i:arr[node])
        {
            if(i!=par)
                maxsum=max(maxsum,fillValues(i,arr,prices,node));
        }
        maxSum[node]=prices[node]+maxsum;
        return maxSum[node];
    }
    void findans(int node,vector<vector<int>>&arr,vector<int>&prices,int sum,int& maxans,int par){
        
        
        maxans=max(maxans,max(sum,maxSum[node]-prices[node]));
        
        int firstMax=-1;
        int secondMax=-1;
        for(auto i:arr[node]){
            if(i!=par){
                if(maxSum[i]>=firstMax){
                    secondMax=firstMax;
                    firstMax=maxSum[i];
                }else if(maxSum[i]>=secondMax){
                    secondMax=maxSum[i];
                }
            }
        }
        for(auto i:arr[node]){
            if(i!=par){
                int tempsum=sum;
                if(firstMax==maxSum[i])
                    tempsum=max(tempsum,secondMax);
                else
                    tempsum=max(tempsum,firstMax);
                findans(i,arr,prices,tempsum+prices[node],maxans,node);
            }
                
        }
    }
    long long maxOutput(int n, vector<vector<int>>& edges, vector<int>& price) {
        
        vector<vector<int>>arr(n);
        for(auto i:edges)
        {
            arr[i[0]].push_back(i[1]);
            arr[i[1]].push_back(i[0]);
        }
        fillValues(0,arr,price,-1);
        int maxans=maxSum[0]-price[0];
        cout<<"the max ans is "<<maxans<<endl;
        findans(0,arr,price,0,maxans,-1);
        return maxans;
            
    }
};