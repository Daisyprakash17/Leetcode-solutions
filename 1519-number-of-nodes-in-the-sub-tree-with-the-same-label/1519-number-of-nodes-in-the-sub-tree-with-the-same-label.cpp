class Solution {
public:
    vector<int>  findans(vector<vector<int>>&v,string &l,int node ,vector<int>&ans,int par)
    {
        vector<int>val(26,0);
        for(auto i:v[node])
        {
            if(i!=par)
            {
                auto temp=    findans(v,l,i,ans,node);
                for(int i=0;i<26;i++)
                    val[i]+=temp[i];
            }
        }
        val[l[node]-'a']++;
        ans[node]=val[l[node]-'a'];
        return val;
    }
    
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string l) {
        vector<vector<int>>v(n);
        
        for(auto i:edges)
        {
            v[i[0]].push_back(i[1]);
            v[i[1]].push_back(i[0]);
                
        }
         vector<int>val(26,0);
        vector<int>ans(n,0);
        
        findans(v,l,0,ans,-1);
        return ans;
        
    }
};