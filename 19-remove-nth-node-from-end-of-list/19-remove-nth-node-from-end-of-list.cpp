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
    
int count(ListNode* head)
{
    int size = 0;
    
    while(head != NULL)
    {
        size++;
        head = head->next;
    }
    
    return size;
}
    
    ListNode* removeNthFromEnd(ListNode* head, int n) 
    {
            
    ListNode* temp = head;
    int size = count(temp);
    
        ListNode* prev = NULL;
        
    // cout<<"size is "<<size<<endl;
    int req = (size - n + 1);
    
    if(req <= 0 || req > size)
    {
        return temp;
    }
    
    size = 1;
    
    // cout<<req<<endl;
    while(head != NULL)
    {
        if(size == req)
        {
            ListNode* trash = head;
            
            if(prev != NULL)
            prev->next = head->next;
            
            if(trash == temp)
                temp = temp->next;
            
            delete(trash);
            break;
        }
        size++;
        
        prev = head;
        head = head->next;
        
        // delete(trash);
        
    }
        
        return temp;
        
    }
};