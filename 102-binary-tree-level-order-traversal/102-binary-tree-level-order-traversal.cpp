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
    vector<vector<int>> levelOrder(TreeNode* root) {
        // for level order traversal we use queue
               vector<vector<int>>final_ans;
                vector<int >ans;
        vector<TreeNode * >cur,pre;
        if(root)
            pre.push_back(root);
        while(pre.size()>0)
        {
            for(auto i:pre)
            {
                ans.push_back(i->val);
                if(i->left)
                cur.push_back(i->left);
               if(i->right)
                cur.push_back(i->right);
            }
            final_ans.push_back(ans);
            pre.clear();
            if(cur.size()>0)
            {
                pre=cur;
                cur.clear();
                ans.clear();
            }
        }
        return final_ans;
    }
};