//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<vector<int>> dp;
    int solve(int i, int j, string &s1, string &s2){
        if(i < 0 or j < 0) return 0;
        
        if(dp[i][j] != -1) return dp[i][j];
        
        if(s1[i] == s2[j]){
            return dp[i][j] = 1 + solve(i-1, j-1, s1, s2);
        }
        
        return dp[i][j] = max(solve(i-1, j, s1, s2), solve(i, j-1, s1, s2));
        
    }
    
    int lcs(string &s1, string &s2) {
        int n = s1.length();
        int m = s2.length();
        
        dp.resize(n+1, vector<int>(m+1, -1));
        
        return solve(n-1, m-1, s1, s2);
        
    }
};



//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s1, s2;
        cin >> s1 >> s2; // Take both the strings as input
        Solution ob;
        cout << ob.lcs(s1, s2) << endl; // Call the lcs function
        cout << "~\n";
    }
    return 0;
}

// } Driver Code Ends