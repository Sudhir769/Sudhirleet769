class Solution {
  public:
    vector<int> shortestPath(int V, vector<vector<int>> &edges, int src) {    
        vector<int> adj[V];
        
        for(auto edge: edges){
            int u = edge[0];
            int v = edge[1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        vector<int> dist(V, 1e9);
        dist[src] = 0;
        queue<int> q;
        q.push(src);
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            int currDist = dist[node];
            
            for(auto neighbour:adj[node]){
                if(dist[neighbour] > currDist + 1){
                    dist[neighbour] = currDist + 1;
                    q.push(neighbour);
                }
            }
        }
        
        for(int i=0; i<V; i++){
            if(dist[i] == 1e9){
                dist[i] = -1;
            }
        }
        return dist;
    
    }
};
