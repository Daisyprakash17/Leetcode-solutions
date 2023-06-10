vector<int>a,tree;
void build(int node,int st,int en)
{

    if(st==en)
    {

        tree[node]=a[st];
        return ;
    }
    int mid=(st+en)/2;
    build(2*node,st,mid);
    build(2*node+1,mid+1,en);
    tree[node]=tree[2*node]+tree[2*node+1];
}
int query(int node,int st,int en,int l,int r)
{

    if(st>r || en<l)
        return 0; // if no overlapping
    if(st>=l && en<=r)
        return tree[node]; // if there is complete over lapping


    // but if here is partial over lapping that means that we will
    // so divide and conquer and call for each of the segment
    int mid=(st+en)/2;
    int left=query(2*node,st,mid,l,r);
    int right=query(2*node+1,mid+1,en,l,r);
    return left+right;
}
void updateNode(int node,int index,int val,int st,int en)
{
    if(st==index && en==index)
    {
        tree[node]=val;
        return ;   
    }
    int mid=(st+en)/2;
    if(index>=st && index<=mid)
        updateNode(2*node,index,val,st,mid);
    if(index>=mid+1 && index<=en)
        updateNode(2*node+1,index,val,mid+1,en);
    tree[node]=tree[2*node]+tree[2*node+1];
}
class NumArray {
public:
    NumArray(vector<int>& nums) {
        a.resize(nums.size(),0);
        tree.resize(4*nums.size()+4,0);
        a=nums;
        build(1,0,nums.size()-1);
    }
    
    void update(int index, int val) {
        updateNode(1,index,val,0,a.size()-1);
    }
    
    int sumRange(int left, int right) {
        return query(1,0,a.size()-1,left,right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */