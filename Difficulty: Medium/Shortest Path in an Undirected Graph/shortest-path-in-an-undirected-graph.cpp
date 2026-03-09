class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        vector<pair<int, int>> adj[n+1];
        
        for(auto edge:edges){
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];
            
            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }
        
        vector<int> parent(n+1), dist(n+1, 1e9);
        for(int i=0; i<=n; i++){
            parent[i] = i;
        }
        dist[1] = 0;
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
        pq.push({0, 1});
        
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            
            int currDist = it.first;
            int currNode = it.second;
            
            for(auto neighbour:adj[currNode]){
                int neighbourNode = neighbour.first;
                int neighbourDist = neighbour.second;
                
                if(currDist + neighbourDist < dist[neighbourNode]){
                    dist[neighbourNode] = currDist + neighbourDist;
                    pq.push({dist[neighbourNode], neighbourNode});
                    parent[neighbourNode] = currNode;
                }
            }
        }
        if(dist[n] == 1e9) return {-1};
        
        vector<int> path;
        int node = n;
        
        while(parent[node] != node){
            path.push_back(node);
            node = parent[node];
        }
        path.push_back(1);
        path.push_back(dist[n]);
        reverse(path.begin(), path.end());
        return path;
    }
};