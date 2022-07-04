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
    bool isCompleteTree(TreeNode* root) {
        int flag=true;
        
        queue<TreeNode *>q;
        q.push(root);
        while(q.size()>0)
        {
            auto it=q.front();
            q.pop();
            if(it==NULL)
                flag=false;
            else
            {
                if(flag==false)
                    return false;
                else
                {
                    q.push(it->left);
                    q.push(it->right);
                }
            }
        }
        return true;
    }
};