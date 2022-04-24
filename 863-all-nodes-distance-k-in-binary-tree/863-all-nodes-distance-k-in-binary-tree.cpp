/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int>ans;
    void getnode(TreeNode * root,int k)
    {
        if(!root)
            return ;
            if(k==0)
            {
                ans.push_back(root->val);
                    return ; 
            }
        getnode(root->left,k-1);
        getnode(root->right,k-1);
    }
    int  findallatk(TreeNode *root,TreeNode* t,int k)
    {
        
        if(root==nullptr)
            return -1;
        if(root==t)
        {
            getnode(root,k);
            return k-1;
        }
        if(root->left)
        {
            int val=findallatk(root->left,t,k);
            if(val!=-1)
            {
                if(val==0)
                {
                    ans.push_back(root->val);
                    return -1;
                }
                else
                {
                    getnode(root->right,val-1);
                    return val-1;
                }
            }
        }
        if(root->right)
        {
            int val=findallatk(root->right,t,k);
            if(val!=-1)
            {
                if(val==0)
                {
                    ans.push_back(root->val);
                    return -1;
                }
                else
                {
                    getnode(root->left,val-1);
                    return val-1;
                }
            }
        }
        return -1;
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        findallatk(root,target,k);
        return ans;
    }
};