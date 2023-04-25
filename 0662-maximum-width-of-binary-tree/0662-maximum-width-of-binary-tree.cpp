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
    int widthOfBinaryTree(TreeNode* root) 
    {
        queue<pair<TreeNode*, long long>> pending;
        pending.push({root, 1});
        
        long long ans = INT_MIN;
        
        while(!pending.empty())
        {
            
            long long n = pending.size();
            long long mini = INT_MAX, maxi = INT_MIN;
            long long count = 0;
            long long last = 0;
            
            for(int i=0; i<n; i++)
            {
                auto pr = pending.front();
                pending.pop();
                
                mini = min(mini, pr.second);
                maxi = max(maxi, pr.second);
                
                if(pr.second - last > 1)count += ((pr.second - last - 1)*2);
                
                if(pr.first->left)pending.push({pr.first->left, count});
                
                count++;
                
                if(pr.first->right)pending.push({pr.first->right, count});
                
                count++;
                
                last = pr.second;
            }
            
            ans = max(ans, (maxi-mini+1));
        }
        
        return ans;
    }
};