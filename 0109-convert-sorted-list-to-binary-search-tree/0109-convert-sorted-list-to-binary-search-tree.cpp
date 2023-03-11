/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    vector<int>v;
    TreeNode* createbst(int start,int end)
    {
            int cen=(start+end)/2;
        TreeNode * node =new TreeNode(v[cen]);
        
        if(start!=cen)
            node->left=createbst(start,cen-1);
        if(end!=cen)
            node->right=createbst(cen+1,end);
        return node;
    }
    TreeNode* sortedListToBST(ListNode* head) {
         while(head)
        {v.push_back(head->val);
            head=head->next;}
        
        if(v.size()==0)
            return nullptr;
        return createbst(0,v.size()-1);
    }
};