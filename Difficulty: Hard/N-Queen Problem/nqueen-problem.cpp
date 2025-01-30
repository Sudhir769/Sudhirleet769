//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    vector<vector<int>> ans;
    vector<vector<char>> grid;
    
    void makeAns(int n){
        
        vector<int> temp;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 'Q'){
                    temp.push_back(j+1);
                }
            }
        }
        ans.push_back(temp);
    }
    
    bool isSafe(int row, int col, int n){
        
        for(int j=0; j<col; j++){
            if(grid[row][j] == 'Q'){
                return false;
            }
        }
        for(int i=0; i<row; i++){
            if(grid[i][col] == 'Q'){
                return false;
            }
        }
        
        for(int i=row, j=col; i>=0 and j>=0; i--, j--){
            if(grid[i][j] == 'Q'){
                return false;
            }
        }
        
        for(int i=row, j=col; i>=0 and j<n; i--, j++){
            if(grid[i][j] == 'Q'){
                return false;
            }
        }
        
        return true;
    }
    
    void solve(int row, int n){
        if(row >= n){
            makeAns(n);
            return;
        }
        
        for(int j=0; j<n; j++){
            if(isSafe(row, j, n)){
                grid[row][j] = 'Q';
                solve(row+1, n);
                grid[row][j] = '.';
            }
        }
    }
    
    vector<vector<int>> nQueen(int n) {
        
        grid.resize(n, vector<char>(n, '.'));
        
        solve(0, n);
        
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        Solution ob;
        vector<vector<int>> ans = ob.nQueen(n);
        if (ans.size() == 0)
            cout << -1 << "\n";
        else {
            sort(ans.begin(), ans.end());
            for (int i = 0; i < ans.size(); i++) {
                cout << "[";
                for (int u : ans[i])
                    cout << u << " ";
                cout << "] ";
            }
            cout << endl;
        }

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends