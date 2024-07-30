//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    vector<string> ans;
    void solve(int i, int j, string path, vector<vector<int>> &mat, int n){
        if(i < 0 or i >= n or j < 0 or j >= n or mat[i][j] == 0){
            return;
        }
        if(i == n-1 and j == n-1){
            ans.push_back(path);
            return;
        }
        mat[i][j] = 0;
        
        solve(i-1, j, path + 'U', mat, n);
        solve(i+1, j, path + 'D', mat, n);
        solve(i, j+1, path + 'R', mat, n);
        solve(i, j-1, path + 'L', mat, n);
        
        mat[i][j] = 1;
        
    }
    vector<string> findPath(vector<vector<int>> &mat) {
        int n = mat.size();
        
        string path = "";
        solve(0, 0, path, mat, n);
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
        vector<vector<int>> m(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++)
                cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends