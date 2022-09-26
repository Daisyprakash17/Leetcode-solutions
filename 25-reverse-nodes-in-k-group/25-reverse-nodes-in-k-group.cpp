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
    bool checkit(ListNode * temp,int k)
    {
        int count=0;
        ListNode * t;
        t=temp;
        while(t!=nullptr && count<k)
        {
            t=t->next;
            count++;
        }
        return count==k;
    }
    
    ListNode* reverseKGroup(ListNode* head, int k) {
        
        ListNode *start,*temp;
        ListNode *last;
        start=nullptr;
        temp=head;
        
        while(checkit(temp,k))
        {
           ListNode * left,*t;
            left=temp;
            
            int count=k-1;
            left=temp;
            t=temp;
            temp=temp->next;
            left->next=nullptr;
            while(count--)
            {  
                ListNode * cur=temp;
                temp=temp->next;
                cur->next=t;
                t=cur; 
            }
            if(start==nullptr)
               { 
                    start=t;
                last=left;
                last->next=temp;
            }
            else
            { 
                last->next=t;
                last=left;
                last->next=temp;
            }  
        }
        return start;
    }
};