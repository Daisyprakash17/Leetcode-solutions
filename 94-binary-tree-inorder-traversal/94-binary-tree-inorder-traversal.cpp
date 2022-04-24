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
        // this solution is using morris traversal
        vector<int>ans;
        TreeNode * cur=root;
        while(cur)
        {
            if(cur->left==nullptr)
            {
                ans.push_back(cur->val);
                cur=cur->right;
            }
            else
            {
                // here we will either link the value of delink the value
                TreeNode * pre=cur->left;
                while(pre->right!=nullptr && pre->right!=cur)
                {
                    pre=pre->right;
                }
                if(pre->right==nullptr)
                {
                    // so this means we have make  link between 
                    // righmost of left tree and cur ndoe
                    //ans.push_back(cur->val);// pre order 
                    pre->right=cur;// making the link
                    cur=cur->left;
                }
                else 
                {
                    // this means there is already a link so remove it
                    pre->right=nullptr;
                    ans.push_back(cur->val);// inorder
                    cur=cur->right;
                }
            }
        }
        return ans;
    }
};