#include<bits/stdc++.h>
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
    vector<int> findMode(TreeNode* root) {
        
        queue<TreeNode *>q;
        int ma=INT_MIN;
        q.push(root);
        map<int,int>m;
        vector<int>ans;
         while(q.size()>0)
        {
            TreeNode * t=q.front();
            q.pop();
            int val=t->val;
            m [val]++;
            if(m[val]>ma)
            {
                ma=m[val];
                ans.clear();
                ans.push_back(val);
                
            }
             else if(ma==m[val])
                 ans.push_back(val);
                if(t->right)
                q.push(t->right);
            if(t->left)
                q.push(t->left);
        }
         
            
        return ans;
    }
};