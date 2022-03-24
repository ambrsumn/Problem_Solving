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
    
    vector<string> ans;
    int flag;
    
    void path(TreeNode* root, string curr)
    {
        if(!root->left && !root->right)
        {
            curr += to_string(root->val);
            ans.push_back(curr);
            return;
        }
        
        curr = curr + to_string(root->val) + "->";

        if(root->left)
            path(root->left, curr);
        
        if(root->right)
            path(root->right, curr);
    }
    
    
    vector<string> binaryTreePaths(TreeNode* root) 
    {
        string curr = "";
        
        path(root, curr);
        
        return ans;
    }
};