class Solution {
public:
    vector<int>vis;
    vector<int>temp;
    int ans=0;
    void findans( )
    {
        
        if(temp.size()==vis.size())
        {
            
                ans++; 
            return ;
        }
        for(int i=0;i<vis.size();i++)
        {
            if(vis[i]==0 && ((i+1)%(temp.size()+1)==0 || (temp.size()+1)%(i+1)==0))
            {
                vis[i]=1;
                temp.push_back(i+1);
                findans();
                vis[i]=0;
                temp.pop_back();
            }
        }
    }
    int countArrangement(int n) {
       
        vector<int>a(n,0); // 0 denote that element is available
        
        vis=a;
        findans();
        return ans;
    }
};