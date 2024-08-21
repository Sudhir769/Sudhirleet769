//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& edges, int n,int M, int src){
        vector<int> adj[n];
        for(auto edge:edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        
        vector<int> dist(n, 1e5);
        priority_queue<pair<int, int>, 
            vector<pair<int, int>>, greater<pair<int, int>>> pq; //{dist, node}
        pq.push({0, src});
        dist[src] = 0;
        
        while(!pq.empty()){
            auto it = pq.top(); pq.pop();
            int dis = it.first;
            int node = it.second;
            
            for(auto neighbor:adj[node]){
                int newDist = 1;
                int adjNode = neighbor;
                
                if(dis + newDist < dist[adjNode]){
                    dist[adjNode] = dis + newDist;
                    pq.push({dist[adjNode], adjNode});
                }
            }
        }
        for(int i=0; i<n; i++){
            if(dist[i] == 1e5){
                dist[i] = -1;
            }
        }
        return dist;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        vector<vector<int>> edges;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for(int j=0; j<2; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        int src; cin >> src;

        Solution obj;

        vector<int> res = obj.shortestPath(edges, n, m, src);

        for (auto x : res){
            cout<<x<<" ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends