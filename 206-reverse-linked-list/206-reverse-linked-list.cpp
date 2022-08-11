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
    
    void rev(ListNode* temp, ListNode* &head)
    {
        if(temp->next == NULL)
            return;
        
        temp = temp->next;
        rev(temp,head);
        
        cout<<temp->val<<endl;
        
        head->val = temp->val;
        head->next = new ListNode();
        head = head->next;
    }
    
    ListNode* reverseList(ListNode* head) 
    {
        if(head == NULL)
            return NULL;
        
        ListNode* temp = head;
        ListNode* ans = new ListNode();
        ListNode* ref = ans;
        
        rev(temp, ans);
        ans->val = head->val;
        ans->next = NULL;
        
        return ref;
    }
};