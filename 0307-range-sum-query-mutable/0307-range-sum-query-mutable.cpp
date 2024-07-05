class NumArray {
public:
    vector<int>nodes;
    vector<int>nums;
    void createtree(int node,int l,int r){
        
        if(l==r){
            nodes[node]=nums[l];
            return ;
        }
        int mid=(l+r)/2;;
        createtree(2*node,l,mid);
        createtree(2*node+1,mid+1,r);
        int left=nodes[2*node];
        int right=nodes[2*node+1];
        nodes[node]=left+right;
    }
    void updatevalue(int node,int index,int val,int l,int r){
        
        if(l==r && l==index){
            nodes[node]=val;
            return ;
        }
        int mid=(l+r)/2;
        if(index<=mid){
            // so this value is in left parts so
            updatevalue(2*node,index,val,l,mid);
        }
        else if(index>=mid+1)
            updatevalue(2*node+1,index,val,mid+1,r);
        nodes[node]=nodes[2*node]+nodes[2*node+1];
    }
    int getsum(int node,int l,int r,int left,int right){
        
        if(r<left || right<l)
            return 0;
        if(left<=l && right>=r)
            return nodes[node];
        
        int mid=(l+r)/2;
        int ll=getsum(2*node,l,mid,left,right);
         int rr=  getsum(2*node+1,mid+1,r,left,right);
        return ll+rr;
        
    }
    NumArray(vector<int>& num) {
        nodes.resize(4*num.size()+5,0);
        nums=num;
        createtree(1,0,num.size()-1);
    }
    
    void update(int index, int val) {
        updatevalue(1,index,val,0,nums.size()-1);
    }
    
    int sumRange(int left, int right) {
        return getsum(1,0,nums.size()-1,left,right);
        return 0;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */