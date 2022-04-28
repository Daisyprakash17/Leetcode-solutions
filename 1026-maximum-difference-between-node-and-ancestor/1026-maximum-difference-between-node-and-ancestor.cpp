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
    int ans=INT_MIN;
    void findans(TreeNode * root,int mi,int ma)
    {
        
         if(root==nullptr)
             return ; 
        
             if(root->val>ma)
            ma=root->val;
        if(root->val<mi)
            mi=root->val; 
        findans(root->right,mi,ma);
        findans(root->left,mi,ma);
        
        ans=max(ans,abs(mi-ma));
        
    }
    int maxAncestorDiff(TreeNode* root) {
        int mi=INT_MAX;
        int ma=INT_MIN;
        findans(root,mi,ma);
        return ans;
    }
};