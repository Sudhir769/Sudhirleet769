//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to find a solved Sudoku.
    
    bool isPossible(vector<vector<int>>& mat, int row, int col, int digit){
        for(int i=0; i<9; i++){
            if(mat[row][i] == digit) return false;
            if(mat[i][col] == digit) return false;
            if(mat[3*(row/3) + i/3][3*(col/3) + i%3] == digit) return false;
        }
        return true;
    }
    
    bool solve(vector<vector<int>>& mat){
        
        for(int i=0; i<9; i++){
            for(int j=0; j<9; j++){
                if(mat[i][j] == 0){
                    
                    for(int digit=1; digit<=9; digit++){
                        
                        if(isPossible(mat, i, j, digit)){
                            mat[i][j] = digit;
                            
                            if(solve(mat) == true){
                                return true;
                            }
                            mat[i][j] = 0;
                        }   
                    }
                    return false;
                }
            }
        }
        return true;
    }
    
    void solveSudoku(vector<vector<int>> &mat) {
        solve(mat);
    }
};

//{ Driver Code Starts.

vector<int> inputLine() {
    string str;
    getline(cin, str);
    stringstream ss(str);
    int num;
    vector<int> res;
    while (ss >> num) {
        res.push_back(num);
    }
    return res;
}

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<vector<int>> grid;
        for (int i = 0; i < 9; i++) {
            vector<int> v = inputLine();
            grid.push_back(v);
        }

        Solution ob;

        ob.solveSudoku(grid);

        for (auto v : grid) {
            for (auto elem : v) {
                cout << elem << " ";
            }
            cout << endl;
        }

        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends