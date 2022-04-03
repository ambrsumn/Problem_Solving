// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
// Function to Build Tree
Node* buildTree(string str)
{   
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
            return NULL;
    
    // Creating vector of strings from input 
    // string after spliting by space
    vector<string> ip;
    
    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);
        
    // Create the root of the tree
    Node* root = new Node(stoi(ip[0]));
        
    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);
        
    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {
            
        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();
            
        // Get the current node's value from the string
        string currVal = ip[i];
            
        // If the left child is not null
        if(currVal != "N") {
                
            // Create the left child for the current node
            currNode->left = new Node(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->left);
        }
            
        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];
            
        // If the right child is not null
        if(currVal != "N") {
                
            // Create the right child for the current node
            currNode->right = new Node(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }
    
    return root;
}

bool isCousins(Node*root , int x , int y);

int main()
{

    int t;
	scanf("%d ",&t);
    while(t--)
    {
        string s;
		getline(cin,s);
        Node* root = buildTree(s);
        int x , y;
        scanf("%d ",&x);
		scanf("%d ",&y);
        if(x==y)
        {
            cout<<"0\n";
            continue;
        }
        cout <<isCousins(root,x,y)<< endl;
    }
    return 1;
}// } Driver Code Ends


/*Complete the function below
Node is as follows:
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
// Returns true if the nodes with values 'a' and 'b' are cousins. Else returns false

    int level(Node* root, int a)
    {
        if(root == NULL)
        return 0;
        
        int x=0;
        
        if(root->data == a || (x = level(root->left, a)) > 0 || (x = level(root->right, a)) > 0)
        return (x+1);
        
        return x;
    }

bool parent(Node* root, int a, int b)
{
    if(root == NULL)
    return true;
    
    if(root->left && root->right)
    {
    if(root->left->data == a && root->right->data == b)
    return false;
    
    if(root->left->data == b && root->right->data == a)
    return false;            
    }
    
    return parent(root->left, a, b) and parent(root->right, a, b);
}


bool isCousins(Node *root, int a, int b)
{
  if(!parent(root, a, b))
  return false;
   
   
   int lvl1 = level(root, a);
   
   int lvl2 = level(root, b);
   
//   cout<<lvl1<<" "<<lvl2<<endl;
   
   if(lvl1 == lvl2)
   return true;
   
   return false;
}