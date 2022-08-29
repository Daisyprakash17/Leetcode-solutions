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
    vector<vector<int>> findans(TreeNode * root,int t,int s)
    {
        if(root==nullptr)
            return {};
        if(!root->left && !root->right  )
        {
            if(root->val+s==t)
            return {{root->val}};
            else
                return {};
        }
        vector<vector<int>>left=findans(root->left,t,s+root->val);
        vector<vector<int>>right=findans(root->right,t,s+root->val); 
        vector<vector<int>>temp;
        for(auto i:left)
           { i.push_back(root->val);
            temp.push_back(i);
           }
        for(auto i:right)
            {
                i.push_back(root->val);
            temp.push_back(i);
        } 
        return temp;
        
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>>temp=findans(root,targetSum,0);
        for(int i=0;i<temp.size();i++)
            reverse(temp[i].begin(),temp[i].end());
        return temp;
    }
};