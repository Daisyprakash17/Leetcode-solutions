 
// in segment we require 4*no of element to prevent error
// understand it by build the segment tree of elemenet
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
class NumArray {
public:
    NumArray(vector<int>& nums) {
        a.resize(nums.size());
        tree.resize(4*nums.size()+4);
        a=nums;
        build(1,0,nums.size()-1);
    }
    
    int sumRange(int left, int right) {
        return query(1,0,a.size()-1,left,right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */