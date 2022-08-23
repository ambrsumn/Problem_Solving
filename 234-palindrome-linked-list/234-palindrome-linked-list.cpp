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
    bool ans = true;
    
    void recur(ListNode* head, ListNode* &temp)
    {
        if(!head->next)return;
        
        head=head->next;
        recur(head, temp);
        
        // cout<<head->val<<" "<<temp->val<<endl;
        
        if(head->val != temp->val)ans=false;
        temp=temp->next;
    }
    
    bool isPalindrome(ListNode* head) 
    {
        if(!head)return true;
        
        recur(head,head);
        
        return ans;
    }
};