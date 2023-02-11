class Solution {
public:
    bool isPossible(int n, vector<vector<int>>& edges) {
        vector<set<int>>arr(n+1);
       
        for(auto i:edges)
        {
            arr[i[0]].insert(i[1]);
            arr[i[1]].insert(i[0]);
          
        }
        vector<int >odd;
        for(int i=1;i<=n;i++)
            if(arr[i].size()%2==1)
                odd.push_back(i); // this node have odd degree
                
        
        // if no of odd degree is more that 5 then it is not possible
        int count=odd.size();
        cout<<count<<endl;
        if(count>=5 || count==1 || count==3)
            return false;
        
        
        if(count==2)
        {
            int a=odd[0];
            int b=odd[1];
            if(arr[a].find(b)==arr[a].end())
                return true ;
            
            for(int i=1;i<=n;i++)
            {
                if(i!=a && i!=b && arr[i].find(a)==arr[i].end() && arr[i].find(b)==arr[i].end())
                    return true;
            }
            return false;
        }
        
        if(count==4)
        {
            int a=odd[0];
            int b=odd[1];
            int c=odd[2];
            int d=odd[3];
            if(arr[a].find(b)==arr[a].end() && arr[c].find(d)==arr[c].end())
                return true;
            if(arr[a].find(c)==arr[a].end() && arr[b].find(d)==arr[b].end())
                return true;
            if(arr[a].find(d)==arr[a].end() && arr[b].find(c)==arr[b].end())
                return true;
            return false;
        }
        
        // this is when count==0
        return true;
        
    }
};