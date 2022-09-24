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
    
    // map<pair<TreeNode*,int>,int> mpp;
    bool recur(TreeNode* root, int t)
    {
        if(!root)return false;
        
        if(!root->left && !root->right)
        {
            if(t-root->val == 0)return true;
            return false;
        }
        
        // if(mpp.count({root,t}) != 0)return mpp[{root,t}];
        
        return recur(root->left, t-root->val) | recur(root->right, t-root->val);
    }
    
    bool hasPathSum(TreeNode* root, int t) 
    {
        return recur(root, t);
    }
};