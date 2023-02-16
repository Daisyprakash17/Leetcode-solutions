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
    int maxDepth(TreeNode* root) {
        
        if(root==nullptr)
            return 0;
        
        queue<pair<TreeNode* ,int>>q;
        q.push({root,1});
        int finalans=1;
        while(q.size()>0)
        {
                TreeNode * node=q.front().first;
            int val=q.front().second;
            q.pop();
            
            finalans=max(finalans,val);
            if(node->left)
                q.push({node->left,val+1});
            if(node->right)
                q.push({node->right,val+1});
        }
            return finalans;
    }
    
};