
class Solution {
public:
    
    pair<ListNode*, ListNode*> getNode(ListNode* root)
    {
        ListNode* slow = root;
        ListNode* fast = root;
        ListNode* prev = NULL;
        
        
        while(fast && fast->next)
        {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        
        return {slow, prev};
    }
    
    TreeNode* sortedListToBST(ListNode* head) 
    {
        if(!head)return NULL;
        
        pair<ListNode*, ListNode*> pr = getNode(head);
        
        TreeNode* root = new TreeNode(pr.first->val);
        if(pr.second)
        {
        pr.second->next = NULL;
        
        root->left = sortedListToBST(head);
        }
        else
            root->left = NULL;
        
        
        root->right = sortedListToBST(pr.first->next);
        
        return root;
    }
};