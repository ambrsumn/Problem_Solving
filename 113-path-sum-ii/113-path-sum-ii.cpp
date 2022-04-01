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
    
    vector<vector<int>> numbers;
    
    
    int summer(vector<int> vec)
    {
        int sum = 0;
        
        for(int i=0; i<vec.size(); i++)
        {
            sum += vec[i];
        }
        
        return sum;
    }
    
    
    void nums(TreeNode* root, vector<int> vec)
    {
        if(!root->left && !root->right)
        {
            vec.push_back(root->val);
            
            numbers.push_back(vec);
            
            return;
        }
        
        
        vec.push_back(root->val);
        
        
        if(root->left)
            nums(root->left, vec);
        
        if(root->right)
           nums(root->right, vec);
        
    }
    
    
    vector<vector<int>> pathSum(TreeNode* root, int target) 
    {
        if(root == NULL)
            return numbers;
        
        vector<int> ans;
        
        nums(root, ans);
        
        vector<vector<int>> returner;
        
        for(int i=0; i<numbers.size(); i++)
        {
            int sum = summer(numbers[i]);
            
            if(sum == target)
                returner.push_back(numbers[i]);
        }
        
        return returner;
    }
};