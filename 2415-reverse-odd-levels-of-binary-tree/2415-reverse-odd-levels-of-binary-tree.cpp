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
    TreeNode* reverseOddLevels(TreeNode* root) {
        
        vector<TreeNode * >cur;
        cur.push_back(root);
        int level=1;
        while(cur.size()>0){
            vector<TreeNode * >temp;
            vector<int>vals;
            for(auto i:cur)
            {
                if(i->left){
                    temp.push_back(i->left);
                    vals.push_back(i->left->val);
                }
                if(i->right){
                    temp.push_back(i->right);
                    vals.push_back(i->right->val);
                }
            }
            if(level==1 && temp.size()>0){
                int sz=vals.size();
                TreeNode * tt;
                for(int i=0;i<cur.size();i++){
                    tt=cur[i];
                    tt->left->val=vals[sz-1];
                    tt->right->val=vals[sz-2];
                    sz-=2;
                }
            }
            cur=temp;
            level=(level+1)%2;
        }
        return root;
    }
};