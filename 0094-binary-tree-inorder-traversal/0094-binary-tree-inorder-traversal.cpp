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
        TreeNode * cur=root;
        while(cur!=nullptr){
            
            if(cur->left==nullptr){
                // this means either left no exist of left if already traversed
                ans.push_back(cur->val);
                cur=cur->right;
            }
            else{
                TreeNode * temp=cur->left;
                // now here will find the right most node of left
                while(temp->right!=nullptr){
                    temp=temp->right;
                }
                
                temp->right=cur;
                TreeNode * t=cur->left;
                cur->left=nullptr;
                cur=t;
            }
        }
        return ans;
    }
};