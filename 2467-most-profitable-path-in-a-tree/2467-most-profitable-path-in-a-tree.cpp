class Solution {
public:
    
    
    pair<int,int> fillbval(vector<vector<int>>&arr,int node,int bob,vector<pair<int,int>>&bval,vector<int>&vis,vector<int>&amount){
        
        vis[node]=1;
        
        int ma=INT_MIN;
        int flag=-1;
        for(auto i:arr[node]){
            if(vis[i]==0){
                pair<int,int>p=fillbval(arr,i,bob,bval,vis,amount);
                ma=max(ma,p.first);
                flag=max(flag, p.second);
            }
        }
        if(ma==INT_MIN)
            ma=0;
        if(node==bob)
            flag=0;
        if(flag==-1)
            ma+=amount[node];
        else
            flag++;
        if(node==bob)
            flag--;
        bval[node]={ma,flag};
        cout<<node<<" "<<ma<<" "<<flag<<endl;
        return {ma,flag};
    }
    int fans=INT_MIN;
    void findans(vector<vector<int>>&arr,int node,vector<pair<int,int>>&bval,vector<int>&vis,int count,int cost,vector<int>&amount){
        cout<<node<<endl;
        vis[node]=1;
        int ans=cost;
        if(count==bval[node].second)
            ans+=amount[node]/2;
        else if(count<bval[node].second)
            ans+=amount[node];
        
        if(bval[node].second==-1)
            ans+=amount[node];
        int flag=0;
        for(auto i:arr[node]){
            if(vis[i]==0){
            findans(arr,i,bval,vis,count+1,ans,amount);
                flag=1;
            }
        }
     
        if(flag==0)
        fans=max(fans,ans);
    }
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        int n=amount.size();
        vector<vector<int>>arr(n);
        
        for(auto i:edges)
        {
            arr[i[0]].push_back(i[1]);
            arr[i[1]].push_back(i[0]);
        }
        vector<pair<int,int>>bval(n);
        vector<int>vis(n,0),dvis(n,0);
        fillbval(arr,0,bob,bval,vis,amount);
         findans(arr,0,bval,dvis,0,0,amount);
        return fans;
    }
};