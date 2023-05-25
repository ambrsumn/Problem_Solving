/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) 
    {
        if(!root)return NULL;
        
        queue<Node*> pending;
        pending.push(root);
        
        while(!pending.empty())
        {
            int n = pending.size();
            
            while(n>0)
            {
                Node* temp = pending.front();
                pending.pop();
                
                if(temp->left)pending.push(temp->left);
                if(temp->right)pending.push(temp->right);
                
                if(n != 1)
                {
                    temp->next = pending.front();
                    // cout<<temp->val<<" "<<temp->next->val<<endl;
                }
                
                else 
                {
                    // cout<<"YES"<<endl;
                    temp->next = NULL;
                }
                
                n--;
            }
            
        }
        
        return root;
    }
};