//{ Driver Code Starts
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

Node* buildList() {
    vector<int> arr;
    string input;
    getline(cin, input);
    stringstream ss(input);
    int number;
    while (ss >> number) {
        arr.push_back(number);
    }
    if (arr.empty()) {
        return NULL;
    }
    int val = arr[0];
    int size = arr.size();

    Node* head = new Node(val);
    Node* tail = head;

    for (int i = 1; i < size; i++) {
        val = arr[i];
        tail->next = new Node(val);
        tail = tail->next;
    }

    return head;
}

void printList(Node* n) {
    while (n) {
        cout << n->data << " ";
        n = n->next;
    }
    cout << endl;
}


// } Driver Code Ends
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution {
  public:
    Node* reverse(Node* head){
        if(head->next == NULL) return head;
        Node* temp = reverse(head->next);
        head->next->next = head;
        head->next = NULL;
        return temp;
    }
    Node* addTwoLists(Node* num1, Node* num2) {
        Node* revNum1 = reverse(num1);
        Node* revNum2 = reverse(num2);
        
        Node* dummy = new Node(0);
        Node* temp = dummy;
        
        int carry = 0;
        while(revNum1 or revNum2 or carry){
            int sum = carry;
            
            if(revNum1){
                sum += revNum1->data;
                revNum1 = revNum1->next;
            }
            if(revNum2){
                sum += revNum2->data;
                revNum2 = revNum2->next;
            }
            
            carry = sum / 10;
            temp->next = new Node(sum % 10);
            temp = temp->next;
        }
        
        temp = reverse(dummy->next);
        while(temp and temp->data == 0){
            temp = temp->next;
        }
    
        return temp;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // To ignore the newline character after the integer input

    while (t--) {
        Node* num1 = buildList();
        Node* num2 = buildList();
        Solution ob;
        Node* res = ob.addTwoLists(num1, num2);
        printList(res);
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends