/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode * findans(ListNode * head)
    {
        if(head==NULL)
            return head;
        int val=head->val;
        head->val=100001;
        ListNode * temp;
        if((!head->next) || (head->next && head->next->val==100001) ) 
            temp=head->next; 
        else 
            temp=findans(head->next);   
        head->val=val;
        return temp;
    }
    ListNode *detectCycle(ListNode *head) {
        return findans(head);
    }
};