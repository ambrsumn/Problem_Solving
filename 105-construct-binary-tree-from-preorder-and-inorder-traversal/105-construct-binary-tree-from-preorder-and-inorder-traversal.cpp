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
    int n=0;
    vector<int> in;
    unordered_map<int,int> mpp;
    
    TreeNode* tbuilder(int left, int right, int k)
    {   
        if(left<0 || right>=n || left>right)return NULL;
        int i=0,j=0,flag=INT_MAX;
        
       for(i=left; i<=right; i++)
       {
           if(mpp[in[i]]<flag)
           {
               flag=mpp[in[i]];
               k=in[i];
               j=i;
           }
       }
        // cout<<k<<endl;
        if(k == INT_MIN)return NULL;
        
        TreeNode* root = new TreeNode(k);
        
        root->left = tbuilder(left, j-1, INT_MIN);
        root->right = tbuilder(j+1, right, INT_MIN);
        
        return root;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) 
    {
        in = inorder;
        n=preorder.size();
        
        int count=1;
        for(auto it : preorder)
        {
            mpp[it]=count;
            count++;
        }
        
        TreeNode* ans = tbuilder(0, n-1, INT_MIN);
        
        return ans;
    }
};