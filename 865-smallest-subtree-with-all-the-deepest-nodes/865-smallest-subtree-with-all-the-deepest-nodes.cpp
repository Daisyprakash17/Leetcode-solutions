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
    
    TreeNode * findans(TreeNode * root,int level,int cur)
    {
            if(level==cur || root==nullptr)
                return root;
        
        TreeNode * left=findans(root->left,level,cur+1);
        TreeNode * right=findans(root->right,level,cur+1);
        
        if(!right)
            return left;
        else if(!left)
            return right;
        else if(right && left)
            return root;
        else
            return nullptr;
    }
    TreeNode *findres ( TreeNode *root)
    {
         int maxi=-1;
        queue<pair<TreeNode * ,int>>q;
        q.push({root,0});
        while(q.size()>0)
        {
            auto temp=q.front().first;
            int val=q.front().second;
            q.pop();
            maxi=max(val,maxi);
            if(temp->right)
                q.push({temp->right,val+1});
            
            if(temp->left)
                q.push({temp->left,val+1});
            
        } 
        return findans(root,maxi,0);
        
      }
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
            return findres(root);
    }
};