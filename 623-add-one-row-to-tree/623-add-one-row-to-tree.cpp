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
    
    TreeNode * addthenodes(TreeNode * root,int val,int d,int l)
    {
        
        if(!root || l>d )
            return root;
         
        if(d==l)
        {
            TreeNode * left=new TreeNode (val);
            TreeNode * right= new TreeNode (val);
            
            left->left=root->left;
            right->right=root->right;
            root->left=left;
            root->right=right;
            return root;

            
        }
        addthenodes(root->left,val,d,l+1);
        addthenodes(root->right,val,d,l+1);
        return root;
    }
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        
        if(depth==1)
        {
            TreeNode * node=new TreeNode (val);
            node->left=root;
            return node;
        }
        
        return addthenodes(root, val, depth,2);
    }
};