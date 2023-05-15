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
class Solution {
public:
    ListNode * first;
    ListNode *second;
    int k;
    int n;
    void findans(ListNode * node,int count)
    {
        if(!node)
        {
            n=count;
            return ;
        }
        count++;
        if(count==k)
        {first=node;
        } 
        findans(node->next,count);
        if(count==n+1-k) 
            second=node;
            
    }
    ListNode* swapNodes(ListNode* head, int kk) {
        k=kk;
        findans(head,0);
        swap(first->val,second->val);
        return head;
    }
};