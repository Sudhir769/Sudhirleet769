//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    
    return temp;
}

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
/* A binary Tree node
struct Node
{
    int data;
    struct Node *left, *right;
};
*/

class Solution
{
public:
    map<Node*, Node*>mp;
    Node* tarNode;
    void solve(Node* root, Node* parent, int target){
        if(root==NULL) return;
        mp[root]=parent;
        if(!tarNode and root->data == target) tarNode = root;
        solve(root->left, root, target);
        solve(root->right, root, target);
    }

    vector <int> KDistanceNodes(Node* root, int target , int k)
    {
        vector<int>ans;
        // map<Node*, Node*>par;
        tarNode = NULL;
        solve(root, NULL, target);
        
        queue<pair<Node*, int>>q;
        q.push({tarNode, k});
        
        map<Node*,bool>vis;
        vis[tarNode] = true;
        
        while(!q.empty()){
            int n = q.size();
            for(int i=0;i<n;i++){
                Node* temp = q.front().first;
                int dis = q.front().second;
                q.pop();
                
                if(dis==0) ans.push_back(temp->data);
                
                if(temp->left and dis>0 and !vis[temp->left]){
                    q.push({temp->left, dis-1});
                    vis[temp->left] = true;
                }
                
                if(temp->right and dis > 0 and !vis[temp->right]){
                    q.push({temp->right, dis-1});
                    vis[temp->right]=true;
                }
                
                if(mp[temp] and dis>0 and !vis[mp[temp]]){
                    q.push({mp[temp], dis-1});
                    vis[mp[temp]]=true;
                }
            }
        }
        
        sort(ans.begin(), ans.end());
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    getchar();
    
    Solution x = Solution();
    
    while(t--)
    {
        string s;
        getline(cin,s);
        Node* head = buildTree(s);
        
        int target, k;
        cin>> target >> k;
        getchar();
        
        vector <int> res = x.KDistanceNodes(head, target, k);
        
        for( int i=0; i<res.size(); i++ )
            cout<< res[i] << " ";
        cout<<endl;
    }
    return 0;
}

// } Driver Code Ends