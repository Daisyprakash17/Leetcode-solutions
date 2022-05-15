/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    
    TreeNode * findans(TreeNode * o,TreeNode * c,TreeNode * t)
    {
        if(o==nullptr)
            return o;
        
        if(o->val==t->val)
        {
            return c;
            
        }
        
        TreeNode * left=findans(o->left,c->left,t);
        TreeNode * right=findans(o->right,c->right,t);
        if(!left)
            return right;
        if(!right)
            return left;
        
        return nullptr;
    }
    TreeNode* getTargetCopy(TreeNode* o, TreeNode* c, TreeNode* t) {
        return findans(o,c,t);    
    }
};