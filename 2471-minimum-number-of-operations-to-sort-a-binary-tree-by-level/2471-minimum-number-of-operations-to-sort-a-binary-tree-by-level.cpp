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
    void fillval(TreeNode * root,map<int,vector<int>>&m,int level){
            
        if(root==nullptr)
            return ;
        
        m[level].push_back(root->val);
        fillval(root->left,m,level+1);
        fillval(root->right,m,level+1);
    }
    int getans(vector<int>&v){
        map<int,int>m;
        for(int i=0;i<v.size();i++){
            m[v[i]]=i;
        }
        
        int  count=0;
        int j=0;
        for(auto i:m){
            if(i.first==v[j]){
            j++;
                continue;

            }
            
            count++;
            int t=v[j];
            swap(v[j],v[i.second]);
            m[t]=i.second;
            j++;
        }
        return count;
    }
    int minimumOperations(TreeNode* root) {
            map<int,vector<int>>m;
            
            fillval(root,m,0);
        cout<<" temp " <<endl;
        int ans=0;
        for(auto i:m)
            ans+=getans(i.second);
        return ans;
    }
};