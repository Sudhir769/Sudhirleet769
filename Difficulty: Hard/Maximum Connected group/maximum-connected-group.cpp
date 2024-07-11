//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class DisjointSet {
    public:
    vector<int> rank, parent, size;

    DisjointSet(int n) {
        rank.resize(n+1,0);
        size.resize(n+1,1);
        parent.resize(n+1);
        for(int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }
    
    int findUParent(int node) {
        if(parent[node] == node) return node;
        return parent[node] = findUParent(parent[node]);
    }
    
    bool isInSameComponent(int u, int v) {
        return (findUParent(u) == findUParent(v));
    }
    
    void unionByRank(int u, int v) {
        int ulp_u = findUParent(u);
        int ulp_v = findUParent(v);
        
        if(ulp_v == ulp_u) return;
        
        if(rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        } else if (rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u;  
        } else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }
    
    void unionBySize(int u, int v) {
        int ulp_u = findUParent(u);
        int ulp_v = findUParent(v);
        
        if(ulp_v == ulp_u) return;
        
        if(size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        } else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
    
};

class Solution {
  public:
    int MaxConnection(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        DisjointSet ds(n*m);
        
        vector<vector<int>> directions = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 0){
                    continue;
                }
                
                for(auto &dir: directions){
                    int nrow = i + dir[0];
                    int ncol = j + dir[1];
                    
                    if(nrow >= 0 and nrow < n and ncol >= 0 and ncol < m){
                        if(grid[nrow][ncol] == 1){
                            int nodeNo = i*m + j;
                            int adjNode = nrow*m + ncol;
                            
                            ds.unionBySize(nodeNo, adjNode);
                        }
                    }
                }
            }
        }
        
        int mx = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 1) continue;
                
                set<int>components;
                for(auto &dir:directions){
                    int nrow = i + dir[0];
                    int ncol = j + dir[1];
                    
                    if(nrow >= 0 and nrow < n and ncol >= 0 and ncol < m){
                        if(grid[nrow][ncol] == 1){
                            components.insert(ds.findUParent(nrow*m + ncol));
                        }
                    }
                }
                int sizeTotal=0;
                for(auto it:components){
                    sizeTotal += ds.size[it];
                }
                mx = max(mx, sizeTotal+1);
            }
        }
        for(int i=0; i<n*m; i++){
            mx = max(mx, ds.size[ds.findUParent(i)]);
        }
        return mx;
    }
};


//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> grid(n, vector<int>(n));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> grid[i][j];
            }
        }

        Solution obj;
        cout << obj.MaxConnection(grid) << "\n";
    }
}

// } Driver Code Ends