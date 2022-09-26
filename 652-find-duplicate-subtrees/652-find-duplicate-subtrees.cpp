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
    map<string ,int>m;
    vector<TreeNode *>ans;
    string findans(TreeNode * root)
    { 
       string left="L";
        if(root->left)
       left= findans(root->left);
        string right="R";
        if(root->right)
        right=findans(root->right);
        string temp=left+to_string(root->val)+right;
        m[temp]++;
        if(m[temp]==2)
            ans.push_back(root);
        return temp;
    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        findans(root);
         
        return ans;
            
    }
};