//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    bool dfs(int node , int vis[], int pathVis[], vector<int>adj[]){
        vis[node]=1;
        pathVis[node]=1;
        
        for(auto it:adj[node]){
            if(!vis[it]){
                if(dfs(it, vis, pathVis, adj)==true){
                    return true;
                }
            }else if(pathVis[it]){
                return true;
            }
        }
        pathVis[node]=0;
        return false;
    }
    bool isCyclic(int V, vector<vector<int>> &edges) {
        vector<int> adj[V];
        
        for(auto edge:edges){
            adj[edge[0]].push_back(edge[1]);
        }
        
        int vis[V]={0};
        int pathVis[V]={0};
        
        for(int i=0; i<V; i++){
            if(!vis[i]){
                if(dfs(i, vis, pathVis, adj)==true) return true;
            }
        }
        return false;
    }
};


//{ Driver Code Starts.

int main() {
    int tc;
    cin >> tc;
    cin.ignore();
    while (tc--) {
        int V, E;
        cin >> V >> E;
        cin.ignore();
        vector<vector<int>> edges;
        for (int i = 1; i <= E; i++) {
            int u, v;
            cin >> u >> v;
            edges.push_back({u, v});
        }

        Solution obj;
        bool ans = obj.isCyclic(V, edges);
        if (ans)
            cout << "true\n";
        else
            cout << "false\n";
    }
    return 0;
}
// } Driver Code Ends