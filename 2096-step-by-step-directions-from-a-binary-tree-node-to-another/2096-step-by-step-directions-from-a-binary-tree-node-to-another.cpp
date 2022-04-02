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

    TreeNode* lowestCommonAncestor(TreeNode* root, int n1, int n2) 
    {
       if(root == NULL || root->val == n1 || root->val == n2)
       return root;
       
       TreeNode* left = lowestCommonAncestor(root->left, n1, n2);
       TreeNode* right = lowestCommonAncestor(root->right, n1, n2);
       
       if(!left)
       return right;
       
       else if(!right)
       return left;
       
       else
       return root;
    }
    
    
    int distance(TreeNode* root, int a, string &curr)
    {
        if(root == NULL)
            return 0;
        
        if(root->val == a)
            return 1;
        
        curr += 'L';
        auto res = distance(root->left, a, curr);
        
        if(res == 1)return 1;
        curr.pop_back();
        
        
        curr += 'R';
         auto mes = distance(root->right, a, curr);
        
        if(mes == 1)return 1;
        curr.pop_back();  
        
        return 0;
    }
    
    
    string getDirections(TreeNode* root, int n1, int n2) 
    {
        TreeNode* lcaa = lowestCommonAncestor(root, n1, n2);
        
        string p1 = "";
        string p2 = "";
        
        distance(lcaa, n1, p1);
        distance(lcaa, n2, p2);
        
        // cout<<p1<<" "<<p2<<endl;
        
        for(int i=0; i<p1.length(); i++)
            p1[i] = 'U';
        
        p1 += p2;
        
        return p1;
        
    }
};