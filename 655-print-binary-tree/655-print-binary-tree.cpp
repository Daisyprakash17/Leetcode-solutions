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
    void findlevel(TreeNode * root,int &level,int count)
    {
        if(!root)
        {
            level=max(level,count);
            return ;
        }
        findlevel(root->left,level,count+1);
        findlevel(root->right,level,count+1);
    }
    void fillit(vector<vector<string>>&ans,TreeNode * root , int left,int right,int level){
        if(root==nullptr)
            return ;
        int mid=(left+right)/2;
        ans[level][mid]=to_string(root->val);
        fillit(ans,root->left,left,mid-1,level+1);
        fillit(ans,root->right,mid+1,right,level+1);
    }
    vector<vector<string>> printTree(TreeNode* root) { 
        int n=0;
        findlevel(root,n ,0);
        int no=(1<<n)-1;
        vector<vector<string>>ans(n,vector<string>(no,""));
        
        fillit(ans,root,0,no,0);
        return ans;
    }
};