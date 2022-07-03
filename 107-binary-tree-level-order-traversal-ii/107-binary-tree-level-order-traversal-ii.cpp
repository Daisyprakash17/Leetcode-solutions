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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
                
        
    vector<TreeNode * >pre;
    vector<TreeNode *>cur;
    vector<vector<int>>ans;
    if(root!=nullptr)
        {
            
            pre.push_back(root);
            cur.push_back(root);
            vector<int>vs;
            vs.push_back(root->val);
            ans.push_back(vs);
        }
    while(cur.size()>0)
    {
        
        cur.clear();
        for(auto i:pre)
        {
            if(i->left!=nullptr)
            cur.push_back(i->left);
            if(i->right!=nullptr)
                cur.push_back(i->right);
        }
        
        vector<int>v;
        for(auto i:cur)
            v.push_back(i->val);
        pre=cur;
        if(v.size()>0)
        ans.push_back(v);
    }
        reverse(ans.begin(),ans.end());
    return ans;
    }
};