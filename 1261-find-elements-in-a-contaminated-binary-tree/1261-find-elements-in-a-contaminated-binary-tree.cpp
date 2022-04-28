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
class FindElements {
public:
    map<int,int>m;
    FindElements(TreeNode* root) {
        
        queue<TreeNode *>q;
        if(root)
        {
            root->val=0;
            q.push(root);
        }
        while(q.size()>0)
        {
            auto t=q.front();
            q.pop();
            int val=t->val;
            m[val]++;
            if(t->left)
            {
                t->left->val=2*val+1;
                q.push(t->left);
            }
            if(t->right)
            {
                t->right->val=2*val+2;
                q.push(t->right);
            }
        }
        
    }
    
    bool find(int target) {
        return m[target];
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */