// { Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};


void printInorder(Node* node)
{
	if (node == NULL)return;
	printInorder(node->left);
	cout<<node->data<<" ";
	printInorder(node->right);
}

Node* constructBinaryTree(int pre[], int preMirror[], int size);

// Driver program to test above functions
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int preOrder[n];
	    int preOrderMirror[n];
	    for(int i=0; i<n; i++)cin>>preOrder[i];
	    for(int i=0; i<n; i++)cin>>preOrderMirror[i];
	    printInorder(constructBinaryTree(preOrder, preOrderMirror, n));
	    cout<<endl;
    }
	return 0;
}// } Driver Code Ends

Node* builder(int pre[], int &i, int lvl, int req)
{
    Node* newnode = new Node(pre[i]);
    
    if(lvl < req)
    {
        lvl++;
        i++;
        
        newnode->left = builder(pre, i, lvl, req);
        newnode->right = builder(pre, i, lvl, req);
    }
    
    else
    {
        // i++;
        return NULL;
    }
    
    return newnode;
}

Node* constructBinaryTree(int pre[], int preMirror[], int size)
{
    int i=0;
    int lvl = log2(size+1);
    
    Node* ans = builder(pre, i, 0, lvl);
    
    return ans;
}