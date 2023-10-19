//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
	public:
	//Function to find the level of node X.
	int nodeLevel(int V, vector<int> adj[], int X) 
	{
	    queue<pair<int, int>>pq;
	    pq.push({0, 0});
	    int vis[V] = {false};
	    vis[0] = true;
	    while(!pq.empty()){
	        int level = pq.front().first;
	        int node =  pq.front().second;
	        pq.pop();
	        
	        if(node==X) return level;
	        
	        for(auto it: adj[node]){
	            if(!vis[it]){
	                pq.push({level+1, it});
	                vis[it] = true;
	            }
	        }
	    }
	    return -1;
	}
};

//{ Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E, X;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    		adj[v].push_back(u);
    	}
    	cin>>X;

    	Solution obj;
    	cout << obj.nodeLevel(V, adj, X) << "\n";
    }

    return 0;
}


// } Driver Code Ends