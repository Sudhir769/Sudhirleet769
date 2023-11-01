//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
  int mod = 1e9+7;
    int solve(int i, int j, vector<vector<int>> &grid, vector<vector<int>>&dp, int n, int m){
        if(i==n and j==m) return 1;
        if(i>n || j>m || grid[i][j]==0) return 0;
        ;
        
        if(dp[i][j]!=-1) return (dp[i][j])%mod;
        
        int down = solve(i+1, j, grid, dp, n, m);
        int right = solve(i, j+1, grid, dp, n, m);
        
        return dp[i][j] = (down + right)%mod;
    }
    
    int uniquePaths(int n, int m, vector<vector<int>> &grid) {
        if(grid[0][0] == 0 or grid[n-1][m-1] == 0) return 0;
        
        vector<vector<int>>dp(n+1, vector<int>(m+1, -1));
        return solve(0, 0, grid, dp, n-1, m-1);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,m,x;
        cin>>n>>m;
        
        vector<vector<int>> grid(n,vector<int>(m));
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                cin>>grid[i][j];
            }
        }

        Solution ob;
        cout << ob.uniquePaths(n,m,grid) << endl;
    }
    return 0;
}
// } Driver Code Ends