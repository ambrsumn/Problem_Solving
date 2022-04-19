// { Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

/* Link list node */
struct Node* partition(struct Node* head, int x);

struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

/* Function to print linked list */
void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

/* Drier program to test above function*/
int main(void) {
    int t;
    cin >> t;

    while (t--) {
        struct Node* head = NULL;
        struct Node* temp = NULL;
        int n;
        cin >> n;

        for (int i = 0; i < n; i++) {
            int value;
            cin >> value;
            if (i == 0) {
                head = new Node(value);
                temp = head;
            } else {
                temp->next = new Node(value);
                temp = temp->next;
            }
        }

        int k;
        cin >> k;

        // Solution ob;

        head = partition(head, k);
        printList(head);
    }

    return (0);
}
// } Driver Code Ends




struct Node* partition(struct Node* temp, int x) {
    
    vector<int> vec;
    // Node* temp = head;
    
    while(temp != NULL)
    {
        Node* trash = temp;
        
        vec.push_back(temp->data);
        temp = temp->next;
        delete(trash);
    }
    
    Node* ans = NULL;
    Node* curr;
    Node* newnode;
    
    
    for(int i=0; i<vec.size(); i++)
    {
        if(vec[i] < x)
        {
            newnode = new Node(vec[i]);
        
        
        if(ans == NULL)
        {
            ans = newnode;
            curr = newnode;
        }
        else
        {
            curr->next = newnode;
            curr = newnode;
        }
        
        }
    }
    
    for(int i=0; i<vec.size(); i++)
    {
        if(vec[i] == x)
        {
            newnode = new Node(vec[i]);
        
        
        if(ans == NULL)
        {
            ans = newnode;
            curr = newnode;
        }
        else
        {
            curr->next = newnode;
            curr = newnode;
        }
        
        }
    }
    
    for(int i=0; i<vec.size(); i++)
    {
        if(vec[i] > x)
        {
            newnode = new Node(vec[i]);
        
        
        if(ans == NULL)
        {
            ans = newnode;
            curr = newnode;
        }
        
        else
        {
            curr->next = newnode;
            curr = newnode;
        }
        
        }
    }
    
    return ans;
}