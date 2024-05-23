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
    
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>ans;
        
        TreeNode * temp=root;
        while(temp!=nullptr){
            
            if(temp->left==nullptr){
                ans.push_back(temp->val);
                temp=temp->right;
                continue;
            }
            
            TreeNode *cur=temp->left;
            
            while(cur->right!=nullptr){
                cur=cur->right;
            }
            cur->right=temp;
            TreeNode * tt=temp->left;
            temp->left=nullptr;
            temp=tt;
        }
        return ans;
    }
};