//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// A Tree node
struct Node {
    int data;
    struct Node *left, *right;
};

// Utility function to create a new node
Node* newNode(int data) {
    Node* temp = new Node;
    temp->data = data;
    temp->left = temp->right = NULL;
    return (temp);
}

Node* buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

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
// User function Template for C++


class Solution {
  public:
    vector<int> in;
    
    void inorder(Node* root){
        if(root){
            inorder(root->left);
            in.push_back(root->data);
            inorder(root->right);
        }
    }
    
    void merge(vector<int>& vec, int low, int mid, int high, int &cnt){
        vector<int>ans(high-low+1);
        int i=low, j=mid+1, k=0;
        
        while(i<=mid and j<=high){
            if(vec[i] <= vec[j]){
                ans[k++] = vec[i++];
            }else{
                ans[k++] = vec[j++];
                cnt += (mid-i+1);
            }
        }
        
        while(i<=mid){
            ans[k++] = vec[i++];
        }
        while(j<=high){
            ans[k++] = vec[j++];
        }
        for(i=low; i<=high; i++){
            vec[i] = ans[i-low];
        }
    }
    
    void mergeSort(vector<int>& vec, int low, int high, int &cnt){
        if(low < high){
            int mid = (low+high)/2;
            mergeSort(vec, low, mid, cnt);
            mergeSort(vec, mid+1, high, cnt);
            merge(vec, low, mid, high, cnt);
        }
    }
    
    int pairsViolatingBST(int n, Node *root) {
        inorder(root);
        
        // for(int i=0; i<n; i++){
        //     for(int j=i+1; j<n; j++){
        //         if(in[i] > in[j]){
        //             cnt++;
        //         }
        //     }
        // }
        
        int cnt=0;
        mergeSort(in, 0, n-1, cnt);;
        
        return cnt;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    getchar();

    while (t--) {

        int n;
        cin >> n;
        getchar();

        string inp;
        getline(cin, inp);

        struct Node* root = buildTree(inp);

        Solution ob;
        int ans = ob.pairsViolatingBST(n, root);
        cout << ans << endl;
    }

    return 0;
}
// } Driver Code Ends