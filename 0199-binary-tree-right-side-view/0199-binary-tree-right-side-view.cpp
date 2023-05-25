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
    vector<int> rightSideView(TreeNode* root) 
    {
        if(!root)return {};
        
        vector<int> ans;
        
        queue<TreeNode*> pending;
        pending.push(root);
        
        while(!pending.empty())
        {
            int n = pending.size();
            vector<int> temp;
            
            while(n>0)
            {
                temp.push_back(pending.front()->val);
                
                if(pending.front()->left)pending.push(pending.front()->left);
                if(pending.front()->right)pending.push(pending.front()->right);
                
                pending.pop();
                n--;
            }
            
            ans.push_back(temp.back());
        }
        
        return ans;
    }
};