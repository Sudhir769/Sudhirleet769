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
        DisjointSet ds(n*n);
        
        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, 1, 0, -1};
        //step-1
        for(int row = 0; row<n; row++){
            for(int col = 0; col<n; col++){
                if(grid[row][col]==0) continue;
                
                for(int ind = 0; ind < 4; ind++){
                    int nrow = row + delRow[ind];
                    int ncol = col + delCol[ind];
                    
                    if(nrow>=0 and ncol<n and ncol>=0 and nrow<n){
                        if(grid[nrow][ncol]==1){
                            int nodeNo = row*n + col;
                            int adjNodeNo = nrow*n + ncol;
                            ds.unionBySize(nodeNo, adjNodeNo); //check
                        }
                    }
                }
            }
        }
        //step-2
        int mx = 0;
        for(int row=0;row<n;row++){
            for(int col=0;col<n;col++){
                if(grid[row][col]==1)continue;
                
                set<int>st;
                for(int ind=0;ind<4;ind++){
                    int nrow = row + delRow[ind];
                    int ncol = col + delCol[ind];
                    
                    if(nrow>=0 and nrow<n and ncol>=0 and ncol<n){
                        if(grid[nrow][ncol]==1){
                           st.insert(ds.findUParent(nrow*n+ncol)); 
                        }
                    }
                }
                int sizeTotal=0;
                for(auto it:st){
                    sizeTotal+=ds.size[it];
                }
                mx = max(mx, sizeTotal+1);
            }
        }
        for(int cellNo=0; cellNo<n*n; cellNo++){
            mx = max(mx, ds.size[ds.findUParent(cellNo)]);
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
        cout<<obj.MaxConnection(grid)<<"\n";
    }
}

// } Driver Code Ends