//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
    public:
    int orangesRotting(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        
        queue<pair<pair<int, int>, int>> q;
        int fresh = 0;
        
        vector<vector<int>> vis(n, vector<int>(m, 0));
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(mat[i][j] == 0) continue;
                
                if(mat[i][j] == 1){
                    fresh++;
                }else{
                    q.push({{i, j}, 0});
                    vis[i][j] = 1;
                }
            }
        }
        
        vector<vector<int>> directions = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
        int t = 0;
        while(!q.empty()){
            int size = q.size();
            while(size--){
                auto it = q.front();
                q.pop();
                
                int row = it.first.first;
                int col = it.first.second;
                int tm  = it.second;
                
                t = max(t, tm);
                
                for(auto dir:directions){
                    int nrow = row + dir[0];
                    int ncol = col + dir[1];
                    
                    if(nrow >=0 and nrow < n and ncol >=0 and ncol < m and
                        !vis[nrow][ncol] and mat[nrow][ncol] == 1){
                            q.push({{nrow, ncol}, tm+1});
                            vis[nrow][ncol] = 1;
                            fresh--;
                        }
                }
            }
        }
        return fresh == 0 ? t:-1;
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> mat(n, vector<int>(m, -1));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> mat[i][j];
            }
        }
        Solution obj;
        int ans = obj.orangesRotting(mat);
        cout << ans << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends