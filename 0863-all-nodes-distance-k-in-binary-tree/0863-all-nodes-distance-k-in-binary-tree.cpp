/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    
    map<TreeNode*, vector<TreeNode*>> mpp;
    
    void dfs(TreeNode* root, TreeNode* parent)
    {
        if(!root)return;
        
        if(root->left)mpp[root].push_back(root->left);
        if(root->right)mpp[root].push_back(root->right);
        if(parent != NULL)mpp[root].push_back(parent);
        
        dfs(root->left, root);
        dfs(root->right, root);
    }
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) 
    {
        if(k == 0)return {target->val};
        
        vector<int> answer;
        dfs(root, NULL);
        queue<TreeNode*> pending;
        pending.push(target);
        target->val = -1;
        int ans = 0;
        
        while(!pending.empty())
        {
            // cout<<ans<<endl;
            int n = pending.size();
            
            for(int i=0; i<n; i++)
            {
                TreeNode* temp = pending.front();
                pending.pop();
                
                for(auto it : mpp[temp])
                {
                    if(it->val != -1)
                    {
                        pending.push(it);
                        if(ans == k-1)answer.push_back(it->val);
                        it->val = -1;
                    }
                }
            }
            
            ans++;
        }
        
        return answer;
    }
};