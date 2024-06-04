//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> src,
        pair<int, int> des) {
            
        // if(grid[des.first][des.second]  == 0){
        //     return -1;
        // }
        
        int n = grid.size();
        int m = grid[0].size();
        
        queue<pair<int, pair<int, int>>>q;
        q.push({0, {src.first, src.second}});
        
        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, 1, 0, -1};
        
        vector<vector<int>>vis(n, vector<int>(m, 0));
        
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            
            int dis = it.first;
            int row = it.second.first;
            int col = it.second.second;
            
            if(it.second == des){
                return dis;
            }
            
            for(int i=0; i<4; i++){
                int nrow = row + delRow[i];
                int ncol = col + delCol[i];
                
                if(nrow < 0 or nrow >= n or ncol < 0 or ncol >= m) continue;
                
                if(grid[nrow][ncol] != 0 and vis[nrow][ncol] == 0){
                    
                    if(make_pair(nrow, ncol) == des){
                        return dis + 1;
                    }
                    q.push({dis + 1, {nrow, ncol}});
                    vis[nrow][ncol] = 1;
                }
            }
            
        }
        return -1;
    }
};


//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }

        pair<int, int> source, destination;
        cin >> source.first >> source.second;
        cin >> destination.first >> destination.second;
        Solution obj;
        cout << obj.shortestPath(grid, source, destination) << endl;
    }
}

// } Driver Code Ends