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
    vector<int> ans;
    
    void recur(TreeNode* root)
    {
        if(!root)return;
        
        ans.push_back(root->val);
        recur(root->left);
        recur(root->right);
    }
    
    vector<int> preorderTraversal(TreeNode* root) 
    {
        recur(root);
        return ans;
    }
};