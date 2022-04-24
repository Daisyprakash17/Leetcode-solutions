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
    vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode * >st;
        if(root)
            st.push(root);
        vector<int>ans;
        while(st.size()>0)
        {
            auto temp=st.top();
            st.pop();
            if(temp->left)
            {
                TreeNode * t=temp->left;
                temp->left=nullptr;
                st.push(temp);
                st.push(t);
            }
            else if(temp->right)
            {
                TreeNode * t=temp->right;
                temp->right=nullptr;
                st.push(temp);
                st.push(t);
            }
            else
            {
                ans.push_back(temp->val);
            }
        }
        return ans;
    }
};