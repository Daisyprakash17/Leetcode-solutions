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
    int ans=0;
    // camera 1
    // need cover -1
    // covered 2
    int findans(TreeNode *root)
    {
         if(root==nullptr)
             return 2;
        int left=findans(root->left);
        int right=findans(root->right);
        
        if(left==-1 || right==-1)
        {
            ans++;
            return 1;
        }
        else if(left==2 && right==2)
            return -1;
        else
            return 2;
            
            
        
    }
    int minCameraCover(TreeNode* root) {
       if(findans(root)==-1)
           ans++;
        return ans;
    }
};