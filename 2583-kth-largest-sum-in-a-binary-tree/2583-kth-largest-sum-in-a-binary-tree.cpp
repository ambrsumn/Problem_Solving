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
    long long kthLargestLevelSum(TreeNode* root, int k) 
    {
        queue<TreeNode*> pending;
        priority_queue<long long> pq;
        
        pending.push(root);
        while(!pending.empty())
        {
            long long curr = 0;
            long long n = pending.size();
            
            for(long long i=0; i<n; i++)
            {
                TreeNode* node = pending.front();
                pending.pop();
                
                curr += node->val;
                
                if(node->left)pending.push(node->left);
                if(node->right)pending.push(node->right);
            }
            
            pq.push(curr);
        }
        
        if(pq.size()>=k)
        {
            while(k != 1)
            {
                pq.pop();
                k--;
            }
            
            return pq.top();
        }
        
        return -1;
    }
};