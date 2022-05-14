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
    vector<int> largestValues(TreeNode* root) {
        
        
        map<int,pair<int,int>>m;
        vector<int>v;
        queue<pair<TreeNode * ,int>>q;
        if(root)
            q.push({root,1});
        
        while(q.size()>0)
        {
            auto it=q.front().first; 
            int level=q.front().second;
            q.pop();
            if(m[level].first==0)
            {
                m[level].first=1;
                m[level].second=it->val;
            }
            else
            {
                m[level].second=max(m[level].second,it->val);
            }
            
            if(it->left)
                q.push({it->left,level+1});
            
            if(it->right)
                q.push({it->right,level+1});
        }
        for(auto i:m)
            v.push_back(i.second.second);
            return v;
        
    }
};