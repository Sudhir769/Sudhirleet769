//{ Driver Code Starts
//

#include <bits/stdc++.h>
using namespace std;

struct Node
{
	int data, height;
	Node *left, *right;
	Node(int x)
	{
		data = x;
		height = 1;
		left = right = NULL;
	}
};

int setHeights(Node* n)
{
	if(!n) return 0;
	n->height = 1 + max( setHeights(n->left) , setHeights(n->right) );
	return n->height;
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
    
    setHeights(root);
    return root;
}

bool isBST(Node *n, int lower, int upper)
{
	if(!n) return 1;
	if( n->data <= lower || n->data >= upper ) return 0;
	return isBST(n->left, lower, n->data) && isBST(n->right, n->data, upper) ;
}

pair<int,bool> isBalanced(Node* n)
{
	if(!n) return pair<int,bool> (0,1);

	pair<int,bool> l = isBalanced(n->left);
	pair<int,bool> r = isBalanced(n->right);

	if( abs(l.first - r.first) > 1 ) return pair<int,bool> (0,0);

	return pair<int,bool> ( 1 + max(l.first , r.first) , l.second && r.second );
}

bool isBalancedBST(Node* root)
{
	if( !isBST(root, INT_MIN, INT_MAX) )
		cout<< "BST voilated, inorder traversal : ";

	else if ( ! isBalanced(root).second )
		cout<< "Unbalanced BST, inorder traversal : ";

	else return 1;
	return 0;
}

void printInorder(Node* n)
{
	if(!n) return;
	printInorder(n->left);
	cout<< n->data << " ";
	printInorder(n->right);
}

struct Node* deleteNode(struct Node* root, int data);

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
        
		int n;
		cin>> n;
		int ip[n];
		for(int i=0; i<n; i++)
			cin>> ip[i];
        
		for(int i=0; i<n; i++)
		{
			root = deleteNode(root, ip[i]);
			
			if( !isBalancedBST(root) )
				break;
		}
        
		if(root==NULL)
			cout<<"null";
		else
			printInorder(root);
		cout<< endl;
        
		getline(cin,s); // to deal with newline char
	}
	return 1;
}

// } Driver Code Ends


/* Node is as follows:

struct Node
{
	int data, height;
	Node *left, *right;
	Node(int x)
	{
		data = x;
		height = 1;
		left = right = NULL;
	}
};

*/

Node* leftRotate(Node* curr){
    Node* toreturn = curr->right;
    Node* temp = curr->right->left;
    curr->right->left=curr;
    curr->right=temp;
    return toreturn;
}

Node* rightRotate(Node* curr){
    Node* toreturn = curr->left;
    Node* temp = curr->left->right;
    curr->left->right=curr;
    curr->left=temp;
    
    return toreturn;
}


Node* deleteNode(Node* root, int data)
{
    function<Node*(Node*,int)>del = [&del](Node* curr, int data)->Node*{
        if(curr==NULL) return NULL;
        
        if(curr->data==data){
            if(curr->left==NULL and curr->right==NULL){
                delete(curr);
                return NULL;
            }
            else if(curr->left==NULL){
                Node* toreturn = curr->right;
                delete(curr);
                return toreturn;
            }
            else if(curr->right==NULL){
                Node* toreturn = curr->left;
                delete(curr);
                return toreturn;
            }
            else{
                Node* next = curr->left;
                while(next->right){
                    next=next->right;
                }
                curr->data=next->data;
                curr->left=del(curr->left, curr->data);
            }
        }
        else if(data < curr->data){
            curr->left = del(curr->left, data);
        }
        else{
            curr->right= del(curr->right, data);
        }
        
        setHeights(curr);
        
        int left, right;
        left=right=0;
        
        if(curr->left){
            left=curr->left->height;
        }
        if(curr->right){
            right= curr->right->height;
        }
        if(left-right > 1){
            left=right=0;
            
            if(curr->left->left){
                left=curr->left->left->height;
            }
            if(curr->left->right){
                right=curr->left->right->height;
            }
            
            if(left-right >= 0){
                curr=rightRotate(curr);
            }
            else{
                curr->left= leftRotate(curr->left);
                curr = rightRotate(curr);
            }
        }
        else if(left-right < -1){
            left=right=0;
            
            if(curr->right->right) right = curr->right->right->height;
            if(curr->right->left) left = curr->right->left->height;
            
            if(left-right<=0){
                curr=leftRotate(curr);
            }else{
                curr->right = rightRotate(curr->right);
                curr= leftRotate(curr);
            }
        }
        
        return curr;
    
    };
    
    return del(root, data);
}