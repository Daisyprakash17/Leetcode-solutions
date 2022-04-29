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
    void findans(TreeNode * root,int &count,int ma)
    {
        if(root==nullptr)
            return  ;
        ma=max(root->val,ma);
        findans(root->left,count,ma );
        findans(root->right,count,ma );
        
        if(root->val>=ma)
            count++;
    }
    int goodNodes(TreeNode* root) {
        int count=0;
        findans(root,count,root->val);
        return count;
    }
};