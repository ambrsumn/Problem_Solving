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
    ListNode *detectCycle(ListNode *head) 
    {
        if(head == NULL)
            return NULL;
        
        ListNode* slow = head;
        ListNode* fast = head;
        
        ListNode* temp = NULL;
        
        while(fast->next != NULL && fast->next->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
            
            if(slow == fast)
            {
                temp = slow;
                break;
            }
        }
        
        if(temp == NULL)
            return NULL;
        
        ListNode* curr = head;
        
        if(temp == curr)
            return temp;
        
        while(temp->next != curr->next)
        {
            curr = curr->next;
            temp = temp->next;
        }
        
        return temp->next;
    }
};