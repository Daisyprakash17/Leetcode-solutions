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
    map<TreeNode * ,int >dp;
   int  findans(TreeNode * root )
    {
        if(root==nullptr)
            return 0 ; 
       if(dp[root]>0)
           return dp[root];
       int ans=0;
       // if we want to consider the current element
       int val=root->val;
       if(root->left)
       {
           val+=findans(root->left->left);
           val+=findans(root->left->right);
       }
       if(root->right)
       {
           val+=findans(root->right->left);
           val+=findans(root->right->right);
       }
       ans=max(val,findans(root->left)+findans(root->right));
       dp[root]=ans;
       return ans;
    }
    int rob(TreeNode* root) {
     
      return   findans(root ); 
    }
};