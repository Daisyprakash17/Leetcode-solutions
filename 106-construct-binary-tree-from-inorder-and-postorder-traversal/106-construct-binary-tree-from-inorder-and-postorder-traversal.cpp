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
    TreeNode * maketree(vector<int>&in,vector<int>&post,int i)
    {
        auto it=find(in.begin(),in.end(),post[i]);
        TreeNode * node=new TreeNode(post[i]);
        vector<int>left(in.begin(),it);
        it++;
        vector<int>right(it,in.end());
        if(right.size()>0)
            node->right=maketree(right,post,i-1);
        if(left.size()>0)
            node->left=maketree(left,post,i-right.size()-1);
        return node;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return maketree(inorder,postorder,inorder.size()-1);
    }
};