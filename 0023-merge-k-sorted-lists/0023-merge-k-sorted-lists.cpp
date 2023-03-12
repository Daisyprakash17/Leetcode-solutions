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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode * ans=new ListNode();
        priority_queue<pair<int,ListNode *>,vector<pair<int,ListNode *>>,greater<pair<int,ListNode *>>> q;
        
        
        for(auto i:lists)
        {
            if(i!=nullptr)
            q.push({i->val,i});
        }
        
       
        if(q.size()==0)
        return nullptr;
        
        
        ListNode* temp =new ListNode(); 
        ans=temp ;
        while(q.size()>0)
        { 
             int val=q.top().first;
             ListNode* t=q.top().second;
            q.pop();
            ListNode *node=new ListNode(val);
            temp->next=node;
            temp=temp->next;
             if(t->next!=nullptr)
            {
                
                
                q.push({t->next->val,t->next});
            }
        }  
        ans=ans->next;
        
        return ans;
    }
};