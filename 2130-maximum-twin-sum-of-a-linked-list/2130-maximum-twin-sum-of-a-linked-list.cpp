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
    map<int,int>m; 
    int n=-1;
    int findans(ListNode * node,int count)
    { 
        if(!node)
        {
            n=count;
            return -1;
        }
        count++;
        int val=findans(node->next,count );
        
        if(count>n/2)
        {
            m[n+1-count]=node->val;
            return -1;
        }
        else
        {
            val=max(val,m[count]+node->val);
            return val;
        }
            
            
    }
    int pairSum(ListNode* head) {
        return findans(head,0);
        
        
    }
};