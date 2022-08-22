/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class CBTInserter {
public:
    TreeNode* head=NULL;
    
    CBTInserter(TreeNode* root) 
    {
        head = root;
    }
    
    int insert(int val) 
    {
        TreeNode* temp = new TreeNode(val);
        
        queue<TreeNode*> pending;
        
        if(head)
        pending.push(head);
        
        while(!pending.empty())
        {
            TreeNode* front = pending.front();
            pending.pop();
            
            if(!front->left)
            {
                front->left = temp;
                return front->val;
            }
            else
                pending.push(front->left);
            
            if(!front->right)
            {
                front->right = temp;
                return front->val;
            }
            else
                 pending.push(front->right);
        }
        
        return 0;
    }
    
    TreeNode* get_root() 
    {
        return head;
    }
};

/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter* obj = new CBTInserter(root);
 * int param_1 = obj->insert(val);
 * TreeNode* param_2 = obj->get_root();
 */