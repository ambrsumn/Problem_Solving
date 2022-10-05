class Solution {
public:
    TreeNode* addOneRow(TreeNode* root, int val, int depth) 
    {
        if(depth == 1)
        {
            TreeNode* head = new TreeNode(val);
            head->left = root;
            return head;
        }
        
        int flag=0;
        queue<TreeNode*> pending;
        pending.push(root);
        vector<TreeNode*> vec;
        int d=1;
        
        while(!pending.empty())
        {
            int n = pending.size();
            
            if(d == depth-1)
            {    
                for(int i=0; i<n; i++)
                {
                    TreeNode* front = pending.front();
                    pending.pop();
                    
                    if(front)
                    {
                    if(!front->left)pending.push(NULL);
                    else pending.push(front->left);
                    
                    if(!front->right)pending.push(NULL);
                    else pending.push(front->right);
                    
                    TreeNode* one = new TreeNode(val);
                    TreeNode* two = new TreeNode(val);
                    
                    front->left = one;
                    front->right = two;
                    
                    vec.push_back(one);
                    vec.push_back(two);
                    }
                }
                break;
            }
            
            else
            {    
                for(int i=0; i<n; i++)
                {
                    TreeNode* front = pending.front();
                    pending.pop();
                    
                    if(front)
                    {
                    if(front->left)pending.push(front->left);
                    else pending.push(NULL);
                    
                    if(front->right)pending.push(front->right);
                    else pending.push(NULL);
                    }
                }
            }
            
            d++;
        }
        
        int count=0;
        for(auto it : vec)
        {
            if(count%2 == 0)
            {
                TreeNode* front = pending.front();
                pending.pop();
                
                it->left = front;
                it->right = NULL;
            }
            
            else
            {
                TreeNode* front = pending.front();
                pending.pop();
                
                it->left = NULL;
                it->right = front;
            }
            count++;
        }
        
        return root;
    }
};