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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int>pre,in,post;
        stack<pair<TreeNode *,int>>st;
        if(root)
            st.push({root,1});
        
        while(st.size()>0)
        {
            auto temp=st.top().first;
            int val=st.top().second;
            st.pop();
            if(val==1)
            {
                // this is for pre order
                pre.push_back(temp->val);
                TreeNode *t=temp->left;
                temp->left=nullptr;
                st.push({temp,2});
                if(t)
                    st.push({t,1});
            }
            else if(val==2)
            {
                // this is for in order
                in.push_back(temp->val);
                TreeNode *t=temp->right;
                temp->right=nullptr;
                st.push({temp,3});
                if(t)
                    st.push({t,1});
                
            }
            else 
                post.push_back(temp->val);
        }
        return post;
    }
};