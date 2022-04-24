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
    TreeNode* maketree(vector<int>&pre,vector<int>&in,int i)
    {
        auto it=find(in.begin(),in.end(),pre[i]);
        TreeNode * node=new TreeNode(pre[i]);
        vector<int>left(in.begin(),it);
        it++;
        vector<int>right(it,in.end());
         if(left.size()>0)
        {
            node->left=maketree(pre,left,i+1);
         }
        if(right.size()>0)
            node->right=maketree(pre,right,i+left.size()+1);
        return node;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return maketree(preorder,inorder,0);
    }
};