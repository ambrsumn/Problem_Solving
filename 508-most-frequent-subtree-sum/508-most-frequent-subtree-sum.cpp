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
    unordered_map<int,int> mpp;
    
    int recur(TreeNode* root)
    {
        if(!root)return 0;
        
        int lsum = 0, rsum=0;
        
        lsum = recur(root->left);
        rsum = recur(root->right);
        
        mpp[(lsum+rsum+root->val)]++;
        
        return (lsum+rsum+root->val);
    }
    vector<int> findFrequentTreeSum(TreeNode* root) 
    {
        vector<int> ans;
        recur(root);
        
        priority_queue<pair<int,int>> pq;
        
        for(auto it : mpp)
            pq.push({it.second, it.first});
        
        int d = pq.top().first;
        
        while(!pq.empty())
        {
            if(pq.top().first != d)break;
            
            while(!pq.empty() && pq.top().first == d)
            {
                ans.push_back(pq.top().second);
                pq.pop();
            }
        }
        
        return ans;
    }
};