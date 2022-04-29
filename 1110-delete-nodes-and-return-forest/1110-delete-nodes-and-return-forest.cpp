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
    TreeNode * findans(TreeNode * root,vector<int>&v,vector<TreeNode *>&ans)
    {
        if(!root)
            return root;
        root->left=findans(root->left,v,ans);
        root->right=findans(root->right,v,ans);
        if(find(v.begin(),v.end(),root->val)!=v.end())
        {
            if(root->left)
                ans.push_back(root->left);
            if(root->right)
                ans.push_back(root->right);
            return nullptr;
        }
        return root;
    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
            vector<TreeNode * >ans;
            auto it=findans(root,to_delete,ans);
        if(it)
            ans.push_back(it);
        return ans;
    }
};