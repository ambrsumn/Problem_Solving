
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) 
    {
        
    vector<vector<int>> ans;

    if (root == NULL)
    {
        return ans;
    }

    queue<TreeNode*> pending;
    
    int level=1;
    
    pending.push(root);

    while (pending.size() != 0)
    {
        int n = pending.size();
        
        vector<int> temp;
        
        for(int i=0; i<n; i++)
        {
            
        TreeNode* front = pending.front();
        pending.pop();
        
        if(front->left)
        pending.push(front->left);
        
        if(front->right)
        pending.push(front->right);
        
        temp.push_back(front->val);
        
        }
        
        if(level%2 == 0)
        {
            reverse(temp.begin(), temp.end());
        }
        
        ans.push_back(temp);
        temp.clear();
        
        level++;
    }    
        
        return ans;
        
    }
};