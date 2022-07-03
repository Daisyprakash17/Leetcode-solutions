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
    TreeNode * findans(TreeNode * root,int low,int high)
    {
        if(!root)
            return root;
        if(root->val>=low && root->val<=high)
        {
            root->left=findans(root->left,low,high);
            root->right=findans(root->right,low,high);
            return root;
        }
        else
        {
          auto left=findans(root->left,low,high);
            auto right=findans(root->right,low,high);
            if(!left)
                return right;
            else
                return left;
        }
    }
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        return findans(root,low,high);
    }
};