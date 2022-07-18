
class Solution {
public:
    bool valid(TreeNode* root)
    {
        if(root->left == NULL && root->right == NULL)
            return true;
        
        return false;
    }
    
    void dfs(TreeNode* root, int &sum)
    {
        if(root == NULL)
            return;
        
        else if(root->left != NULL && valid(root->left))
        {
            sum += root->left->val;
        }
        
        dfs(root->left, sum);
        dfs(root->right, sum);
    }
    
    int sumOfLeftLeaves(TreeNode* root) 
    {
        int sum = 0;
        dfs(root, sum);
        
        return sum;
    }
};