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
    int findBottomLeftValue(TreeNode* root) {
        int ans=0;
        
        queue<TreeNode *>q;
        if(root)
        {
            ans=root->val;
            q.push(root);
            q.push(nullptr);
        }
        while(q.size()>0)
        {
            auto it=q.front();
            q.pop();
            if(it==nullptr)
            {
                if(q.size()>0)
                {
                    q.push(nullptr);
                    ans=q.front()->val;
                }
                
            }
            else
            {
                if(it->left)
                    q.push(it->left);
                if(it->right)
                    q.push(it->right);
            }
        }
        return ans;
    }
};