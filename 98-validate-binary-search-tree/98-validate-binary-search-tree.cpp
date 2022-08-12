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
    
    void inorder(TreeNode* root, vector<int> &vec, set<int> &st)
    {
        if(!root)
            return;
        
        inorder(root->left, vec, st);
        vec.push_back(root->val);
        st.insert(root->val);
        inorder(root->right, vec, st);
    }
    
    bool check(TreeNode* root)
    {
        if(!root)
            return true;
        
        if(!root->left && !root->right)
            return true;
        
        if(root->left && root->left->val >= root->val)
            return false;
        
        if(root->right && root->right->val <= root->val)
            return false;
        
        return isValidBST(root->left) and isValidBST(root->right);
    }
    
    bool isValidBST(TreeNode* root) 
    {
        vector<int> vec;
        set<int> st;
        inorder(root, vec, st);
        if(!is_sorted(vec.begin(), vec.end())) return false;
        if(st.size() != vec.size())return false;
        
        return check(root);
        
        // cout<<ans<<ans2<<endl;
        // for(auto it : vec)
        //     cout<<it<<" ";
        // cout<<endl;
    }
};