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
    
    map<TreeNode*, vector<TreeNode*>> mpp;
    TreeNode* home = NULL;
    int st;
    
    void dfs(TreeNode* root, TreeNode* parent)
    {
        if(!root)return;
        
        if(root->val == st)home = root;
        
        if(root->left)mpp[root].push_back(root->left);
        if(root->right)mpp[root].push_back(root->right);
        if(parent != NULL)mpp[root].push_back(parent);
        
        dfs(root->left, root);
        dfs(root->right, root);
    }
    
    int amountOfTime(TreeNode* root, int start) 
    {
        st = start;
        int ans = -1;
        dfs(root, NULL);
        
        queue<TreeNode*> pending;
        pending.push(home);
        
        // map<TreeNode*, int> visited;
        home->val = -1;
        
        
//         for(auto it : mpp)
//         {
//             cout<<it.first->val<<" : ";
            
//             for(auto itt : it.second)
//             {
//                 cout<<itt->val<<" ";
//             }
//             cout<<endl;
//         }
        
        while(!pending.empty())
        {
            ans++;
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
                        it->val = -1;
                    }
                }
            }
            // cout<<endl;
        }
        
        return ans;
    }
};