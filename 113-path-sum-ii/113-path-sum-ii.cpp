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
class Solution {
public:
    
    vector<vector<int>> ans;
    
    void check(TreeNode* root, vector<int> vec, int sum, int target)
    {
        
        if(!root->left && !root->right && (sum + root->val) == target)
        {
            vec.push_back(root->val);
            ans.push_back(vec);
            
            return;
        }
        
        if(!root->left && !root->right && (sum + root->val) != target)
            return;
        
        
        vec.push_back(root->val);
        sum += root->val;
        
        if(root->left)
            check(root->left, vec, sum, target);
        
        if(root->right)
            check(root->right, vec, sum, target);
        
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) 
    {
        if(root == NULL)
            return ans;
        
        vector<int> curr;
        
        check(root, curr, 0, targetSum);
        
        return ans;
        
    }
};