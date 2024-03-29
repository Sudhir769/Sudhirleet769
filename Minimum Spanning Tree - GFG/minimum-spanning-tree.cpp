//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class DisjointSet{
    public:
    vector<int>par;
    
    DisjointSet(int V){
        par.resize(V+1);
        for(int i=0;i<=V;i++){
            par[i]=i;
        }
    }
    int find(int x){
        if(x==par[x]) return x;
        
        return par[x] = find(par[x]);
    }
    
    void unionSet(int u, int v){
        par[find(u)] = find(v);
    }
};

class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        vector<pair<int,pair<int,int>>>edges;
        for(int i=0;i<V;i++){
            for(auto it:adj[i]){
                int node = i;
                int adjNode = it[0];
                int edgeW = it[1];
                
                edges.push_back({edgeW,{node, adjNode}});
            }
        }
        sort(edges.begin(), edges.end());
        DisjointSet ds(V);
        int mstSum=0;
        
        for(auto it:edges){
            int wt = it.first;
            int u = it.second.first;
            int v = it.second.second;
            
            if(ds.find(u)!=ds.find(v)){
                mstSum+=wt;
                ds.unionSet(u,v);
            }
        }
        return mstSum;
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends