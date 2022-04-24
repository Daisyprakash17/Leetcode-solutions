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
    int findleft(TreeNode *root)
    {
         
        int count=0;
        while(root)
        {
            root=root->left;
            count++;
        }
        return count;
    }
    int findright(TreeNode * root)
    {
         
        int count=0;
        while(root)
        {
            root=root->right;
            count++;
        }
        return count;
    }
    int findans(TreeNode * root)
    {
            if(root==nullptr)
                return 0;
        int left=findleft(root->left);
        int right=findright(root->right);
         if(left==right)
        {
            return pow(2,right+1)-1;
            
        }
        return findans(root->left)+findans(root->right)+1;
    }
    int countNodes(TreeNode* root) {
        return findans(root);
    }
};