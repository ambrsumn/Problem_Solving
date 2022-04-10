// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;
struct Node
{
	int key;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    key = x;
	    left = NULL;
	    right = NULL;
	}
};

Node* buildTree(int inorder[], int levelOrder[], int iStart, int iEnd,int n);
void printPreorder(Node* node)
{
    if (node == NULL)
       return;
    cout << node->key << " ";
    printPreorder(node->left);
    printPreorder(node->right);
    
}
int main()
{
    int t;
    cin>>t;
    while(t--){
    int n;
    cin>>n;
    int in[n],level[n];
    for(int i=0;i<n;i++){
        cin>>in[i];
    }
    for(int i=0;i<n;i++){
        cin>>level[i];
    }
    Node *root=NULL;
    root = buildTree(in, level, 0, n - 1,n);
    printPreorder(root);
    cout<<endl;
    }
    return 0;
}// } Driver Code Ends


/*Complete the function below
Node is as follows:
struct Node
{
    int key;
    struct Node* left, *right;
};
*/

int search(int inorder[], int key, int strt, int end)
{
    int i;
    for(i=strt; i<=end; i++)
    {
        if(inorder[i] == key)
        break;
    }
    
    return i;
}

int what(int inorder[], int levelorder[], int strt, int end, int n)
{
    int flag=0;
    int i;
    
    for(i=0; i<n; i++)
    {
        for(int j=strt; j<=end; j++)
        {
            if(levelorder[i] == inorder[j])
            {
                flag=1;
                break;
            }
        }
        if(flag == 1)
        break;
    }
    
    return levelorder[i];
}

Node* builder(int in[], int lvl[], int inStrt, int inEnd, int n)
{
    if (inStrt > inEnd)
        return NULL;
 
    
    int curr = what(in, lvl, inStrt, inEnd, n);
    Node* tNode = new Node(curr);
 
    
    if (inStrt == inEnd)
        return tNode;
 
 
    int inIndex = search(in, curr, inStrt, inEnd);
    
    
    tNode->left = builder(in, lvl, inStrt, inIndex - 1, n);
    tNode->right = builder(in, lvl, inIndex + 1, inEnd, n);
 
    return tNode;
}

Node* buildTree(int in[], int lvl[], int iStart, int iEnd,int n)
{
    Node* ans = builder(in, lvl, 0, n-1, n);
    
    return ans;
}