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
    TreeNode* replaceValueInTree(TreeNode* root) 
    {
        queue<vector<TreeNode*>> pending;
        int curr = 0;
        
        pending.push({root});
        curr = root->val;
        
        while(!pending.empty())
        {
            int n = pending.size();
            int temp = curr;
            curr = 0;
            
            for(int i=0; i<n; i++)
            {
                vector<TreeNode*> vec = pending.front();
                pending.pop();
                
                int pend=0;
                
                for(int i=0; i<vec.size(); i++)
                {
                    pend += vec[i]->val;
                }
                
                for(int i=0; i<vec.size(); i++)
                {
                    vector<TreeNode*> nw;
                    vec[i]->val = (temp - pend);
                    
                    if(vec[i]->left)
                    {
                        nw.push_back(vec[i]->left);
                        curr += nw.back()->val;
                    }
                    if(vec[i]->right)
                    {
                        nw.push_back(vec[i]->right);
                        curr += nw.back()->val;
                    }
                    
                    pending.push(nw);
                }
                
            }
        }
        
        return root;
    }
};