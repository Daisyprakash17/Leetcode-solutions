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
    pair<int,int> findans(TreeNode * root,int &ans)
    {
            if(root==nullptr)
                return {0,0};
        int sum=0;
        int count=0;
        pair<int,int>temp;
        
        
        temp=findans(root->left,ans);
        sum+=temp.first;
        count+=temp.second;
        
        temp=findans(root->right,ans);
        sum+=temp.first;
        count+=temp.second;
        
        sum+=root->val;
        count++;
        
        if(root->val==sum/count)
        ans++;
        return {sum,count};
        
        
    }
    int averageOfSubtree(TreeNode* root) {
        int ans=0;
        findans(root,ans);
        return ans;
    }
};