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
    
ListNode* last=NULL;
ListNode* prev = NULL;
ListNode* next = NULL;
ListNode* two = NULL;
ListNode* curr = NULL;
    
    void counter(int i, ListNode* temp, int l, int r, ListNode* &prev,ListNode* &two, ListNode* &curr)
    {
        while(temp != NULL)
        {
        // cout<<i<<endl;
        
        if(i == l-1)
            prev=temp;
        
        if(i == l)
            curr = temp;
        
        if(i == r)
            two = temp;
        
        i++;
        temp = temp->next;
        }
    }
    
    
    ListNode* reverseBetween(ListNode* head, int left, int right) 
    {
        if(left == right)
            return head;
        
        counter(1, head, left, right, prev, two, curr);
        
        if(two->next != NULL)
        last = two->next;
        
        while(last != two)
        {
            next = curr->next;
            curr->next = last;
            
            last = curr;
            curr = next;
        }
        
        if(prev != NULL)
        prev->next = last;
        
        else
            return last;
        
        return head;
    }
};