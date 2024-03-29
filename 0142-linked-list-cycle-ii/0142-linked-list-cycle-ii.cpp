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
   
    ListNode *detectCycle(ListNode *head) {
        
        if(head==nullptr || head->next==nullptr)
            return NULL;
        ListNode * slow,*fast,*entry;
        slow=head;
        fast=head;
        entry=head;
        while(fast->next && fast->next->next)
        {
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast)
            {
                while(entry!=slow)
                {
                    entry=entry->next;
                    slow=slow->next;
                }
                return entry;
            }
        }
        return NULL;
    }
};