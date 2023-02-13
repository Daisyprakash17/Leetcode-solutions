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
    map<int,pair<int,int>>m;
    int fillit(TreeNode * root)
    {
        if(root==nullptr)
            return 0;
        int l=fillit(root->left);
        int r=fillit(root->right);
        m[root->val]={l,r};
        return max(l,r)+1;
    }
    map<int,int>res;
    void fillres(TreeNode *root,int count,int ma)
    {
        if(root==nullptr)
            return ; 
        ma=max(count,ma);
        count++;
        res[root->val]=ma;
        fillres(root->left,count,max(ma,count+m[root->val].second));
        fillres(root->right,count,max(ma,count+m[root->val].first));
    }
    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
            fillit(root);
            fillres(root->left,0,m[root->val].second);
            fillres(root->right,0,m[root->val].first);
        
        vector<int>ans;
        for(auto i:queries)
            ans.push_back(res[i]);
        return ans;
    }
    
};