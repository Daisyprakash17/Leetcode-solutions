class TreeAncestor {
public:
    int par[50005][21];
    TreeAncestor(int n, vector<int>& parent) { 
        for(int i=0;i<n;i++)
            par[i][0]=parent[i];
        for(int i=1;i<20;i++)
        {
            for(int j=0;j<n;j++)
            {
                    int p=par[j][i-1];
                    if(p!=-1)
                        p=par[p][i-1];
                par[j][i]=p;
            }
        }
    }
    
    int getKthAncestor(int node, int k) {
        
        for(int i=0;i<20;i++)
        {
            if((k&(1<<i))==(1<<i))
            {
                node=par[node][i];
                if(node==-1)
                    return node;
            }
        }
        return node;
        
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */