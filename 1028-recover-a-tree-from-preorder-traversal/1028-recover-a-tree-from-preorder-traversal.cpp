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
    TreeNode * maketree(vector<pair<int,int>>&v,int &in,int level)
    {
        if(in>=v.size())
            return nullptr;
        if(v[in].second<level)
            return nullptr;  
        
            TreeNode *temp=new TreeNode(v[in].first);
            in++;
            temp->left=maketree(v,in,level+1);
            temp->right=maketree(v,in,level+1);
        
        return temp;
        
            
    }
    TreeNode* recoverFromPreorder(string s) {
        vector<pair<int,int>>v;
        int count=0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='-')
                count++;
            else
            {
                int val=0;
                while(i<s.size() && s[i]!='-')
                {
                    val=val*10+(s[i]-'0');
                    i++;
                }
                i--;
                v.push_back({val,count});
                count=0;
            }
        } 
        
        int in=0;
        return  maketree(v,in,0);
       
    }
};