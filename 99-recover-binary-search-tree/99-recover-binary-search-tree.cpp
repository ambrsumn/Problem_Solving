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
    vector<int> ino, sor;
    int val1=0,val2=0;
    
    void inorder(TreeNode* root)
    {
        if(!root)return;
        
        inorder(root->left);
        ino.push_back(root->val);
        inorder(root->right);
    }
    
    void change(TreeNode* root)
    {
        if(!root)return;
        
        change(root->left);
        if(root->val == val1)root->val=val2;
        else if(root->val == val2)root->val=val1;
        change(root->right);
    }
    
    void recoverTree(TreeNode* root) 
    {
        inorder(root);
        
        sor = ino;
        sort(sor.begin(), sor.end());
        
        for(int i=0; i<ino.size(); i++)
        {
            if(sor[i] != ino[i])
            {
                val1=sor[i];
                val2=ino[i];
                break;
            }
        }
        change(root);
        
        return;
    }
};