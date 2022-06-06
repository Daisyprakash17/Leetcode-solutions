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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode * temp=headB;
        
        while(temp)
        {
            temp->val*=-1;
            temp=temp->next;
        }
        ListNode * ans=nullptr;
        while(headA)
        {
            if(headA->val<0)
            {
                ans=headA;
                break;
            }
            headA=headA->next;
            
        }
        while(headB)
        {
            headB->val*=-1;
            headB=headB->next;
        }
        return ans;
    }
};