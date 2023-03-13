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
    
    bool comp(TreeNode* l, TreeNode* r)
    {
        if(!l && r)return false;
        if(!r && l)return false;
        if(!l && !r)return true;
        
        if(l->val != r->val)return false;
        
        return comp(l->left, r->right) and comp(l->right, r->left);
    }
    
    bool isSymmetric(TreeNode* root) 
    {
        if(!root)return true;
        return comp(root->left, root->right);
    }
};