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
    int ans=INT_MIN;
    int curr=0;
    
    void summ(ListNode* root, ListNode* &temp)
    {
        if(root == NULL)
            return;
        
        summ(root->next, temp);
        
        curr = root->val + temp->val;
        ans = max(ans, curr);
        temp = temp->next;
    }
    
    int pairSum(ListNode* head) 
    {
        summ(head, head);
        return ans;
    }
};