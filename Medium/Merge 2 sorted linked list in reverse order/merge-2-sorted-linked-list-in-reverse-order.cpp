//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

/* Link list Node */
struct Node
{
    int data;
    struct Node* next;
};

void print(struct Node *Node)
{
    while (Node!=NULL)
    {
        cout << Node->data << " ";
        Node = Node->next;
    }
}


Node *newNode(int data)
{
    Node *temp = new Node;
    temp->data = data;
    temp->next = NULL;
    return temp;
}


// } Driver Code Ends


/*



The structure of linked list is the following

struct Node
{
    int data;
    Node* next;
};

*/
class Solution
{
    public:
    Node* next_node(Node* node, int val){
        Node* newNode = new Node();
        newNode->data = val;
        node->next = newNode;
        newNode->next = NULL;
        return newNode;
    }
    
    Node* reverse(Node* node){
        Node* prev = NULL;
        Node* cur = node;
        Node* next = NULL;
        
        while(cur != NULL){
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        
        return prev;
    }
    
    struct Node * mergeResult(Node *node1,Node *node2)
    {
        // your code goes here
              if(node1 == NULL){
            return reverse(node2);
        }
        if(node2 == NULL)return reverse(node1);
        
         Node* head = new Node();
        
        if(node1->data <= node2->data){
            head->data = node1->data;
            node1 = node1->next;
            
        }
        else {
            head->data = node2->data;
            node2 = node2->next;
        }
        Node* new_head = head;
        
        while(node1 != NULL && node2 != NULL){
            if(node1->data <= node2->data){
                next_node(head,node1->data);
                head = head->next;
                node1 = node1->next;
            }
            else {
                next_node(head,node2->data);
                head = head->next;
                node2 = node2->next;
            }
        }
        while(node1 != NULL){
            next_node(head,node1->data);
                head = head->next;
                node1 = node1->next;
        }
        while(node2 != NULL){
             next_node(head,node2->data);
                head = head->next;
                node2 = node2->next;
        }
        
        head = reverse(new_head);
        return head;

    }  
};





//{ Driver Code Starts.

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int nA;
        cin>>nA;
        int nB;
        cin>>nB;

        struct Node* headA=NULL;
        struct Node* tempA = headA;

        for(int i=0;i<nA;i++)
        {
            int ele;
            cin>>ele;
            if(headA==NULL)
            {
                headA=tempA=newNode(ele);

            }else{
                tempA->next = newNode(ele);
				tempA=tempA->next;
            }
        }

        struct Node* headB=NULL;
        struct Node* tempB = headB;


        for(int i=0;i<nB;i++)
        {
            int ele;
            cin>>ele;
            if(headB==NULL)
            {
                headB=tempB=newNode(ele);

            }else{
                tempB->next = newNode(ele);
				tempB=tempB->next;
            }
        }
        
        Solution ob;
        struct Node* result = ob.mergeResult(headA,headB);

        print(result);
        cout<<endl;


    }
}

// } Driver Code Ends