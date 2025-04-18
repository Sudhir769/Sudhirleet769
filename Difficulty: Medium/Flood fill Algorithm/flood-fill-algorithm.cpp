//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    void dfs(int sr, int sc, vector<vector<int>>&ans, vector<vector<int>>&image,
        int newColor, int delRow[], int delCol[], int iniColor){
            int n = ans.size();
            int m = ans[0].size();
            
            ans[sr][sc]=newColor;
            
            for(int i=0;i<4;i++){
                int nrow = sr + delRow[i];
                int ncol = sc + delCol[i];
                
                if(nrow>=0 and nrow<n and ncol>=0 and ncol<m and
                    ans[nrow][ncol]!=newColor and image[nrow][ncol]==iniColor){
                        dfs(nrow, ncol, ans, image, newColor, delRow, delCol, iniColor);
                    }
            }
        }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,  int newColor) {
        int iniColor = image[sr][sc];
        
        vector<vector<int>>ans=image;
        
        int delRow[]={-1,0,1,0};
        int delCol[]={0,1,0,-1};
        
        dfs(sr, sc, ans, image, newColor, delRow, delCol, iniColor);
        
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> image(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++)
                cin >> image[i][j];
        }
        int sr, sc, newColor;
        cin >> sr >> sc >> newColor;
        Solution obj;
        vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
        for (auto i : ans) {
            for (auto j : i)
                cout << j << " ";
            cout << "\n";
        }

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends