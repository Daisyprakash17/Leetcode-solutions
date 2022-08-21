class SnapshotArray {
public:
    map<int,vector<pair<int,int>>>m;
    int count=0;
    vector<int>v;
    set<int>in;
    int n;
    SnapshotArray(int length) {
        v.resize(length);
        for(int i=0;i<length;i++)
            v[i]=0;
        n=length;
    }
    
    void set(int index, int val) {
        in.insert(index);
        v[index]=val;
    }
    
    int snap() {
       if(count==0)
       {
           for(int i=0;i<n;i++)
            m[i].push_back({count,v[i]});
               
       }
        else
        for(auto i:in)
            m[i].push_back({count,v[i]});
        
        count++;
         in.clear();
     return  count-1;
    }
    
    int get(int index, int snap_id) {
        pair<int,int>p;
        p.first=snap_id;
        p.second=0;
        auto it=lower_bound(m[index].begin(),m[index].end(),p);
        if(it==m[index].end())
            it--;
        if(((*it).first)>snap_id)
            it--;
        return ((*it).second);
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */