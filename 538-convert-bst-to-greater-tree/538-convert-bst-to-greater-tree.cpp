
class Solution {
public:
    void total(TreeNode* root, int &sum)
    {
        if(root == NULL)
            return;
        
        sum += root->val;
        
        total(root->left, sum);
        total(root->right, sum);
    }
    
    void dfs(TreeNode* &root, int &tot)
    {
        if(root == NULL)
            return;
        
        dfs(root->left, tot);
        
        int temp = root->val;
        root->val = tot;
        tot -= temp;
        
        dfs(root->right, tot);
    }
    
    TreeNode* convertBST(TreeNode* root) 
    {
        int sum = 0;
        total(root, sum);
        
        dfs(root, sum);
        
        return root;
    }
};