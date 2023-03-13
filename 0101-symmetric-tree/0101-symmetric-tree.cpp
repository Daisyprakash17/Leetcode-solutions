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
    bool check(TreeNode * a,TreeNode*b)
    {
            if(a==nullptr && b!=nullptr)
                return false;
            else if(a!=nullptr && b==nullptr)
                return false;
            else if(a ==nullptr && b==nullptr)
                return true;
        else
        {
            return (check(a->right,b->left)&& check(a->left,b->right)&&(a->val==b->val));
        }
    }
    bool isSymmetric(TreeNode* root) {
        return check(root->left,root->right);   
    }
};