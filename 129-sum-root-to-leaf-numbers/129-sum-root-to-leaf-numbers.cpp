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
    vector<int> numbers;
    
    void nums(TreeNode* root, string num)
    {
        if(!root->left && !root->right)
        {
            num = num + to_string(root->val);
            numbers.push_back(stoi(num));
            
            return;
        }
        
        
        num = num + to_string(root->val);
        
        
        if(root->left)
            nums(root->left, num);
        
        if(root->right)
           nums(root->right, num);
    }
    
    
    int sumNumbers(TreeNode* root) 
    {
        if(root == NULL)
            return 0;
        
        
        // string curr = "";
        
        nums(root, "");
        
        int ans=0;
        
        for(auto it : numbers)
        {
            cout<<it<<" ";
            ans += it;
        }
        
        
        return ans;
    }
};