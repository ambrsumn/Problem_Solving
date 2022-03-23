// { Driver Code Starts
#include <iostream>

using namespace std;

struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};



Node *swapkthnode(Node* head, int num, int K);

void addressstore(Node **arr, Node* head)
{
    Node* temp = head;
    int i = 0;
    while(temp){
        arr[i] = temp;
        i++;
        temp = temp->next;
    }
}

bool check(Node ** before, Node **after, int num, int K)
{
    if(K > num)
        return 1;
    return (before[K-1] == after[num - K]) && (before[num-K] == after[K-1]);
}

int main()
{
    int T;
    cin>>T;
    while(T--){
        int num, K , firstdata;
        cin>>num>>K;
        int temp;
        cin>>firstdata;
        Node* head = new Node(firstdata);
        Node* tail = head;
        for(int i = 0; i<num - 1; i++){
            cin>>temp;
            tail->next = new Node(temp);
            tail = tail->next;
        }
        
        Node *before[num];
        addressstore(before, head);
        
        head = swapkthnode(head, num, K);
        
        Node *after[num];
        addressstore(after, head);
        
        if(check(before, after, num, K))
            cout<<1<<endl;
        else
            cout<<0<<endl;
    }
}
// } Driver Code Ends



Node* traverse(Node* temp, int req)
{
    int size = 1;
    Node* head = temp;
    
    while(head != NULL && size != req)
    {
         head = head->next;
         size++;
    }
    
    return head;
}

Node *swapkthnode(Node* head, int num, int k)
{
    Node* temp = head;
    
    if(k == num)
    {
        k = 1;
    }
    
    int pre = (k-1);
    int post = (num-k);

    if(num < k)
    {
        return head;
    }
    
    else if(k == (num-k+1))
    {
        return head;
    }
    
    else if(k == 1)
    {
        Node* t2 = traverse(head, post);
        Node* d2 = t2->next;
        
        t2->next = temp;
        d2->next = temp->next;
        
        temp->next = NULL;
        return d2;
    }
    
    else if(k == (num/2) && num%2 == 0)
    {
        Node* t1 = traverse(head, pre);
        Node* d1 = t1->next;
        Node* d2 = d1->next;
        
        t1->next = d2;
        d1->next = d2->next;
        d2->next = d1;
        
        return temp;
    }
    else
    {
    Node* t1 = traverse(head, pre);
    head = temp;
    Node* t2 = traverse(head, post);
    
    Node* d1 = t1->next;
    Node* d2 = t2->next;
    head = d1->next;
    
    t1->next = d2;
    t2->next = d1;
    
    d1->next = d2->next;
    d2->next = head;
    
    // print(temp)
    }
    return temp;
}
