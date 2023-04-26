
class Solution {
public:
    
    map<TreeNode*, vector<TreeNode*>> mpp;
    TreeNode* home = NULL;
    int st;
    
    void dfs(TreeNode* root, TreeNode* parent)
    {
        if(!root)return;
        
        if(root->val == st)home = root;
        
        if(root->left)mpp[root].push_back(root->left);
        if(root->right)mpp[root].push_back(root->right);
        if(parent != NULL)mpp[root].push_back(parent);
        
        dfs(root->left, root);
        dfs(root->right, root);
    }
    
    int amountOfTime(TreeNode* root, int start) 
    {
        st = start;
        int ans = -1;
        dfs(root, NULL);
        
        queue<TreeNode*> pending;
        pending.push(home);
        home->val = -1;
        
        while(!pending.empty())
        {
            ans++;
            int n = pending.size();
            
            for(int i=0; i<n; i++)
            {
                TreeNode* temp = pending.front();
                pending.pop();
                
                for(auto it : mpp[temp])
                {
                    if(it->val != -1)
                    {
                        pending.push(it);
                        it->val = -1;
                    }
                }
            }
        }
        
        return ans;
    }
};