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
    
    TreeNode* maketree(int start, int end, vector<int> vec)
    {
        if(start>end)
            return NULL;
        
        int mid = (start+end)/2;
        TreeNode* root = new TreeNode(vec[mid]);
        
        
        root->left = maketree(start, mid-1, vec);
        
        root->right = maketree(mid+1, end, vec);
        
        return root;
    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums) 
    {
        TreeNode* root = maketree(0, (nums.size()-1), nums);
        
        return root;
    }
};