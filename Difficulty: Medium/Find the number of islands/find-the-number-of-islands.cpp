//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to find the number of islands.
    vector<vector<int>> directions = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}, {-1, -1}, {-1, 1}, {1, 1}, {+1, -1}};
    int n, m;
    void dfs(int i, int j, vector<vector<char>>& grid, vector<vector<int>>& vis){
        if(i < 0 or i>= n or j < 0 or j >= m or vis[i][j] == 1 or grid[i][j] == '0'){
            return;
        }
        
        vis[i][j] = 1;
        
        for(auto dir: directions){
            int nrow = i + dir[0];
            int ncol = j + dir[1];
            
            dfs(nrow, ncol, grid, vis);
        }
    }
    
    int numIslands(vector<vector<char>>& grid) {
        n = grid.size();
        m = grid[0].size();
        
        int cnt = 0;
        vector<vector<int>> vis(n, vector<int> (m, 0));
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == '1' and vis[i][j] == 0){
                    cnt++;
                    dfs(i, j, grid, vis);
                }
            }
        }
        return cnt;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}
// } Driver Code Ends