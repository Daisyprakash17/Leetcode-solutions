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
    TreeNode * findans(TreeNode * root)
    {
        if(root==nullptr)
            return root;
        root->left=findans(root->left);
        root->right=findans(root->right);
        
        if(root->left || root->right)
            return root;
        if(root->val==0)
            root=nullptr;
        return root;
            
    }
    TreeNode* pruneTree(TreeNode* root) {
    
        return findans(root);
    }
};