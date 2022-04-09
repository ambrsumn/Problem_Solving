// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
};

Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    
    return temp;
}

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
    Node* root = newNode(stoi(ip[0]));
        
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
            currNode->left = newNode(stoi(currVal));
                
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
            currNode->right = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }
    
    return root;
}


 // } Driver Code Ends
/*
// node structure:

struct Node
{
    int data;
    Node* left;
    Node* right;
};

*/



class Solution{

    public:
    
    void parent(Node *root, unordered_map<Node*,Node*> &m) {
        queue<Node*> q;
        q.push(root);
        while(!q.empty()) {
            int n=q.size();
            while(n--) {
                Node *curr=q.front(); q.pop();
                if(curr->left) {
                    m[curr->left]=curr;
                    q.push(curr->left);
                }
                if(curr->right) {
                    m[curr->right]=curr;
                    q.push(curr->right);
                }
            }
        }
    }
    
    Node *epicenter(Node *root, int target) {
        queue<Node*> q;
        q.push(root);
        while(!q.empty()) {
            int n=q.size();
            while(n--) {
                Node *curr=q.front(); q.pop();
                if(curr->data==target) return curr;
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
            }
        }
    }
    
    int sum_at_distK(Node* root, int target, int k) {
        unordered_map<Node*,Node*> m;
        parent(root,m);
        int ans=target, lvl=0;
        Node *node=epicenter(root,target);
        unordered_set<Node*> vis;
        queue<Node*> q;
        q.push(node);
        vis.insert(node);
        while(!q.empty()) {
            if(lvl==k) break;
            int n=q.size();
            while(n--) {
                Node *curr=q.front(); q.pop();
                if(curr->left&&vis.find(curr->left)==vis.end()) {
                    ans+=curr->left->data;
                    q.push(curr->left);
                    vis.insert(curr->left);
                }
                if(curr->right&&vis.find(curr->right)==vis.end()) {
                    ans+=curr->right->data;
                    q.push(curr->right);
                    vis.insert(curr->right);
                }
                if(m[curr]&&vis.find(m[curr])==vis.end()) {
                    ans+=m[curr]->data;
                    q.push(m[curr]);
                    vis.insert(m[curr]);
                }
            }
            lvl++;
        }
        return ans;
    }

};


// { Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    getchar();
    
    while(t--)
    {
        string s;
        getline(cin,s);
        Node* root = buildTree(s);
        
        int target,k;
        cin>> target >> k;
        getchar();
        Solution obj;
        cout<< obj.sum_at_distK(root,target,k) << endl;
    }
	return 0;
}

  // } Driver Code Ends