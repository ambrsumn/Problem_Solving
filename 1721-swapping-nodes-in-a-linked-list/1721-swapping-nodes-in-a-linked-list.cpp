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
    
ListNode* traverse(ListNode* temp, int req)
{
    int size = 1;
    ListNode* head = temp;
    
    while(head != NULL && size != req)
    {
         head = head->next;
         size++;
    }
    
    return head;
}
    int countNodes(ListNode* head)
    {
        int size=0;
        
        while(head != NULL)
        {
            size++;
            head = head->next;
        }
        
        return size;
    }
    
    ListNode* swapNodes(ListNode* head, int k) 
    {
        
   ListNode* temp = head;
        int num = countNodes(temp);
        temp = head;
    
    if(k == num)
    {
        k = 1;
    }
    
    int pre = (k-1);
    int post = (num-k);

    if(num < k)
    {
        return head;
    }
    
    else if(k == (num-k+1))
    {
        return head;
    }
    
    else if(k == 1)
    {
        ListNode* t2 = traverse(head, post);
        ListNode* d2 = t2->next;
        
        t2->next = temp;
        d2->next = temp->next;
        
        temp->next = NULL;
        return d2;
    }
    
    else if(k == (num/2) && num%2 == 0)
    {
        ListNode* t1 = traverse(head, pre);
        ListNode* d1 = t1->next;
        ListNode* d2 = d1->next;
        
        t1->next = d2;
        d1->next = d2->next;
        d2->next = d1;
        
        return temp;
    }
    else
    {
    ListNode* t1 = traverse(head, pre);
    head = temp;
    ListNode* t2 = traverse(head, post);
    
    ListNode* d1 = t1->next;
    ListNode* d2 = t2->next;
    head = d1->next;
    
    t1->next = d2;
    t2->next = d1;
    
    d1->next = d2->next;
    d2->next = head;
    
    // print(temp)
    }
    return temp;
    }
};