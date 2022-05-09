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
    map<long long ,int>m; 
    long long  maxi=0;
    long long  findans(TreeNode * root)
    {
        if(!root)
            return 0;
        long long  val=root->val+findans(root->left)+findans(root->right);
        m[val]++;
        if(m[val]>maxi)
            maxi=m[val];
            
        return val;
    }
    vector<int> findFrequentTreeSum(TreeNode* root) {
            
        vector<int >ans;
        if(!root)
            return ans;
        findans(root);
        for(auto i:m)
            if(i.second==maxi)
                ans.push_back(i.first);
        return ans;
    }
};