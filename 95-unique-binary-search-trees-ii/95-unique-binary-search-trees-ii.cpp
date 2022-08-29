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
    TreeNode * maketree(TreeNode * root,int val)
    {
        if(root==nullptr)
            return nullptr;
        TreeNode * temp=new TreeNode(root->val+val);
        temp->left=maketree(root->left,val);
        temp->right=maketree(root->right,val);
        return temp;
    }
    vector<TreeNode*> generateTrees(int n) {
        vector<vector<TreeNode*>>ans(9);
        TreeNode * root=new TreeNode(1);
        ans[0].push_back(nullptr);
        ans[1].push_back(root);
        
        for(int i=2;i<=n;i++)
        {
            
            for(int j=i;j>0;j--)
            { 
                int l=j-1;
                int r=i-j;
                for(auto le:ans[l])
                {
                    TreeNode * left=maketree(le,0);
                    for(auto re:ans[r])
                    { 
                        TreeNode * right=maketree(re,j);
                        TreeNode * temp=new TreeNode (j);
                        temp->left=left;
                        temp->right=right;
                        ans[i].push_back(temp);
                    }
                }
            }
        }
        return ans[n];
        
    }
};