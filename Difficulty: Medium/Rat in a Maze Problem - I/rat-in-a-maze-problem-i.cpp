//{ Driver Code Starts
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
    cin.ignore();
    while (t--) {
        string input;
        getline(cin, input);
        vector<vector<int>> mat;
        string innerArray;
        bool isInsideArray = false;

        for (char c : input) {
            if (c == '[') {
                if (isInsideArray) {
                    innerArray.clear();
                }
                isInsideArray = true;
            } else if (c == ']') {
                if (isInsideArray && !innerArray.empty()) {
                    vector<int> row;
                    stringstream ss(innerArray);
                    int num;

                    while (ss >> num) {
                        row.push_back(num);
                        if (ss.peek() == ',')
                            ss.ignore();
                        while (isspace(ss.peek()))
                            ss.ignore();
                    }

                    mat.push_back(row);
                    innerArray.clear();
                }
                isInsideArray = false;
            } else if (isInsideArray) {
                if (!isspace(c)) {
                    innerArray += c;
                }
            }
        }

        Solution obj;
        vector<string> result = obj.findPath(mat);
        sort(result.begin(), result.end());

        if (result.empty())
            cout << "[]";
        else
            for (int i = 0; i < result.size(); i++)
                cout << result[i] << " ";
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends