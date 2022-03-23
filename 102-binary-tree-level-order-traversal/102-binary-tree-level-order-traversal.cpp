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
    vector<vector<int>> levelOrder(TreeNode* root) 
    {
        vector<vector<int>> ans;
        
        if(root == NULL)
            return ans;
        
        queue<TreeNode* > pending;
        
        pending.push(root);
        
        while(!pending.empty())
        {
            int n=pending.size();
            vector<int> temp;
            
            for(int i=0; i<n; i++)
            {
                TreeNode* front = pending.front();
                pending.pop();
                
                if(front->left)
                {
                    pending.push(front->left);
                }
                
                if(front->right)
                {
                    pending.push(front->right);
                }
                
                temp.push_back(front->val);
            }
            
            ans.push_back(temp);
            temp.clear();
        }
        
        return ans;
        
    }
};