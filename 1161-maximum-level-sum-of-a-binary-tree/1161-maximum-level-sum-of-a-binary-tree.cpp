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
    int maxLevelSum(TreeNode* root) 
    {
        queue<TreeNode*> pending;
        priority_queue<pair<long long,int>> pq;
        
        pending.push(root);
        int count=1;
        while(!pending.empty())
        {
            long long curr = 0;
            int n = pending.size();
            
            for(long long i=0; i<n; i++)
            {
                TreeNode* node = pending.front();
                pending.pop();
                
                curr += node->val;
                
                if(node->left)pending.push(node->left);
                if(node->right)pending.push(node->right);
            }
            
            pq.push({curr, count});
            count++;
        }
        
        int temp = pq.top().first;
        int ans = pq.top().second;
        
        while(!pq.empty() && pq.top().first == temp)
        {
            ans = min(ans, pq.top().second);
            pq.pop();
        }
        
        return ans;
    }
};