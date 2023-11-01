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
    pair<pair<int,int>,int> findans(TreeNode *root){
        
        pair<pair<int,int>,int>left,right;
        left=right={{0,0},0};
        if(root->left)
            left=findans(root->left);
        if(root->right)
            right=findans(root->right);
        
        if(left.second==INT_MIN || right.second==INT_MIN)
            return {{0,0},INT_MIN};
        
        if(((root->left==nullptr) || (left.first.second<root->val)) && ((root->right==nullptr) || (right.first.first>root->val))){
            int mi,ma;
            mi=ma=root->val;
            if(root->left!=nullptr)
                mi=left.first.first;
            
            if(root->right!=nullptr)
                ma=right.first.second;
            int sum=left.second+right.second+root->val;
            ans=max(ans,sum);
            return {{mi,ma},sum};
        }
        else
            return {{0,0},INT_MIN};
    }
    int maxSumBST(TreeNode* root) {
        findans(root);
        return ans;
    }
};