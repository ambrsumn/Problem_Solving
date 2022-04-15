// { Driver Code Starts
//Initial template for C++

/* A O(n) iterative program for construction of BST from preorder traversal */
#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left child
   and a pointer to right child */
typedef struct Node
{
    int data;
    struct Node *left, *right;
} Node;

// A Stack has array of Nodes, capacity, and top
typedef struct Stack
{
    int top;
    int capacity;
    Node* *array;
} Stack;

// A utility function to create a new tree node
Node* newNode( int data )
{
    Node* temp = (Node *)malloc( sizeof( Node ) );
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

// A utility function to create a stack of given capacity
Stack* createStack( int capacity )
{
    Stack* stack = (Stack *)malloc( sizeof( Stack ) );
    stack->top = -1;
    stack->capacity = capacity;
    stack->array = (Node **)malloc( stack->capacity * sizeof( Node* ) );
    return stack;
}

// A utility function to check if stack is full
int isFull( Stack* stack )
{
    return stack->top == stack->capacity - 1;
}

// A utility function to check if stack is empty
int isEmpty( Stack* stack )
{
    return stack->top == -1;
}

// A utility function to push an item to stack
void push( Stack* stack, Node* item )
{
    if( isFull( stack ) )
        return;
    stack->array[ ++stack->top ] = item;
}

// A utility function to remove an item from stack
Node* pop( Stack* stack )
{
    if( isEmpty( stack ) )
        return NULL;
    return stack->array[ stack->top-- ];
}

// A utility function to get top node of stack
Node* peek( Stack* stack )
{
    return stack->array[ stack->top ];
}

bool canRepresentBST(int pre[], int n)
{
    // Create an empty stack
    stack<int> s;

    // Initialize current root as minimum possible
    // value
    int root = INT_MIN;

    // Traverse given array
    for (int i=0; i<n; i++)
    {
        // If we find a node who is on right side
        // and smaller than root, return false
        if (pre[i] < root)
            return false;

        // If pre[i] is in right subtree of stack top,
        // Keep removing items smaller than pre[i]
        // and make the last removed item as new
        // root.
        while (!s.empty() && s.top()<pre[i])
        {
            root = s.top();
            s.pop();
        }

        // At this point either stack is empty or
        // pre[i] is smaller than root, push pre[i]
        s.push(pre[i]);
    }
    return true;
}


// A utility function to print postorder traversal of a Binary Tree
void printPostorder (Node* node)
{
    if (node == NULL)
        return;
    printPostorder(node->left);
    printPostorder(node->right);
    printf("%d ", node->data);
}

// The main function that constructs BST from pre[]
Node* post_order (int *, int );

int main()
{
    // Note that size of arr[] is considered 100 according to
    // the constraints mentioned in problem statement.
    int arr[1000], x, t, n;

    // Input the number of test cases you want to run
    cin >> t;

    // One by one run for all input test cases
    while (t--)
    {
        // Input the size of the array
        cin >> n;

        // Input the array
        for (int i=0; i<n; i++)
            cin >> arr[i];

        printPostorder(post_order(arr, n));
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends


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

int what(int inorder[], int pre[], int strt, int end, int n)
{
    int flag=0;
    int i;
    
    for(i=0; i<n; i++)
    {
        for(int j=strt; j<=end; j++)
        {
            if(pre[i] == inorder[j])
            {
                flag=1;
                break;
            }
        }
        if(flag == 1)
        break;
    }
    
    return pre[i];
}

Node* builder(int pre[], int in[], int start, int end, int n)
{
    if(start > end)
    return NULL;
    
    int curr = what(in, pre, start, end, n);
    Node* newnode = newNode(curr);
    
    if(start == end)
    return newnode;
    
    int index = search(in, curr, start, end);
    
    newnode->right = builder(pre, in, index + 1, end, n); 
    newnode->left = builder(pre, in, start, index - 1, n);
    
    return newnode;
}

Node* post_order(int pre[], int size)
{
    int in[size];
    
    for(int i=0; i<size; i++)
        in[i] = pre[i];
    
    sort(in, in+size);
    
    return builder(pre, in, 0, size-1, size);
}
