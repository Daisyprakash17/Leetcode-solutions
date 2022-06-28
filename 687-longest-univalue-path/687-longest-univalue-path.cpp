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
    int ans=-1;
    int findans(TreeNode * root,int par)
    {
        if(!root)
            return 0;
         int flag=root->val==par;
         
        
        int left;
        int right;
        int res=0;
        int temp=0;
        if(flag)
        {
            left=findans(root->left,par);
            right=findans(root->right,par);
            
            res=max(left,right)+1;
            temp=left+right+1;
        }
        else
        {
            left=findans(root->left,root->val);
            right=findans(root->right,root->val);
            res=0;
            temp=left+right+1;
            
        }
        ans=max(temp,ans);
        return res;
            
    }
    int longestUnivaluePath(TreeNode* root) {
        if(!root)
            return 0;
         findans(root,root->val);
        return ans-1;
    }
};