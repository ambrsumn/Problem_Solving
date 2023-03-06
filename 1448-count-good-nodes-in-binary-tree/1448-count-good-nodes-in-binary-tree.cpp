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
    
    // int ans=0;
    int inorder(TreeNode* root, int maxi)
    {
        if(!root)return 0;
        
        int curr = 0;
        if(root->val >= maxi)curr=1;
        
        return (curr + inorder(root->left, max(maxi, root->val)) + inorder(root->right, max(maxi, root->val)));
    }
    
    int goodNodes(TreeNode* root) 
    {
        int maxi = INT_MIN;
        return inorder(root, maxi);
    }
};