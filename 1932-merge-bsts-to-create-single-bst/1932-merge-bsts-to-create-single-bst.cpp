/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool check(TreeNode * root,int low,int high,unordered_map<int,int>&m)
    {
        if(root==nullptr)
            return true;
        if(root->val>=low && root->val<=high)
        {
            m[root->val]=0;
            if(check(root->left,low,root->val,m)==false || check(root->right,root->val,high,m)==false)
                return false;
            else
                return true;
        }
        else
            return false;
    }
    TreeNode* canMerge(vector<TreeNode*>& trees) {
        unordered_map<int,TreeNode*>child;
        unordered_map<int,TreeNode*>par;
        unordered_map<int,int>m;
        int flag=1;
        for(auto i:trees){
            if(par[i->val])
                flag=0;
            else
            par[i->val]=i;
            TreeNode * temp;
            m[i->val]=1;
            if(i->left){
                temp=i->left;
                if(child[temp->val])
                    flag=0;
                else
                child[temp->val]=temp;
                m[temp->val]=1;
            }
            if(i->right){
                temp=i->right;
                if(child[temp->val])
                    flag=0;
                else
                child[temp->val]=temp;
                m[temp->val]=1;
            }
        }
        if(flag==0)
            return nullptr;
        for(auto i:par)
        {
            if(child[i.second->val]){
                child[i.second->val]->left=i.second->left;
                child[i.second->val]->right=i.second->right;
                par[i.second->val]=nullptr;
            }
        }
        TreeNode *root=nullptr;
        int count=0;
        for(auto i:par)
            if(i.second!=nullptr){
                root=i.second;
                count++;
            }
        if(count!=1)
            return nullptr;
        if(check(root,0,INT_MAX,m)){
                for(auto i:m)
                    if(i.second==1)
                        return nullptr;
            return root;
        }
        else
            return nullptr;
    }
};