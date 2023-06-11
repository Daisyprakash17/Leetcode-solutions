vector<unordered_map<int,int>>tree;
int n;
class RangeFreqQuery {
public:
    void build(int node,int st,int en,vector<int>&arr)
    {
        if(st==en)
        {
            tree[node][arr[st]]=1;
            return ;
        }
        int mid=(st+en)/2;
        build(2*node,st,mid,arr);
        build(2*node+1,mid+1,en,arr);
        unordered_map<int,int>temp;
        for(auto i:tree[2*node])
            temp[i.first]+=i.second;
        for(auto i:tree[2*node+1])
            temp[i.first]+=i.second;
        tree[node]=temp;
    }
    int getans(int node,int st,int en,int left,int right,int value)
    {
         if(st>right || en<left)
            return 0; // no overlapping
        if(st>=left && en<=right)
            return tree[node][value];
        int mid=(st+en)/2;
        int l=getans(2*node,st,mid,left,right,value);
        int r=getans(2*node+1,mid+1,en,left,right,value);
        return l+r;
    }
    RangeFreqQuery(vector<int>& arr) {
        tree.clear();
        tree.resize(4*arr.size()+2);
        for(auto i:tree)
            i.clear();
        n=arr.size();
        build(1,0,arr.size()-1,arr); 
        for(int i=1;i<14;i++)
        {
            cout<<"the value of tree node "<<i<<endl;
            for(auto j:tree[i])
                cout<<j.first<<" "<<j.second<<endl;
            cout<<endl;
        }
    }
    
    int query(int left, int right, int value) {
         return getans(1,0,n-1,left,right,value);
    }
};

/**
 * Your RangeFreqQuery object will be instantiated and called as such:
 * RangeFreqQuery* obj = new RangeFreqQuery(arr);
 * int param_1 = obj->query(left,right,value);
 */