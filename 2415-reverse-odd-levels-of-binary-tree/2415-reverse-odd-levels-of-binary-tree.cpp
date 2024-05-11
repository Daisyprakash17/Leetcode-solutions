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
        
        vector<TreeNode*>cur;
        vector<TreeNode*>prev;
        cur.push_back(root);
        int flag=0;
        while(cur.size()>0){
            
            for(auto i:cur)
            {
                if(i->left)
                prev.push_back(i->left);
                if(i->right)
                prev.push_back(i->right);
            }
            if(flag==0 ){
                
                int i=0;
                int j=prev.size()-1;
                while(i<=j){
                    swap(prev[i]->val,prev[j]->val);
                    i++;
                    j--;
                }
            }
            
            flag=(flag+1)%2;
            cur=prev;
            prev.clear();
        }
        return root;
    }
};