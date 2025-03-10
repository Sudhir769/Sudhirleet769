//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<vector<int>>dp;
    int solve(int i, int j, string &s, string &t){
        if(i<0) return j+1;
        if(j<0) return i+1;
        if(dp[i][j] != -1)  return dp[i][j];
        if(s[i]==t[j]){
            return dp[i][j] = solve(i-1, j-1, s, t);
        }
        return dp[i][j] = 1+ min(solve(i-1, j, s, t), min(solve(i, j-1, s, t), solve(i-1, j-1, s, t)));
    }
    int editDistance(string s, string t) {
        int n = s.size();
        int m = t.size();
        dp.resize(n+1, vector<int>(m+1, -1));
        return solve(n-1, m-1, s, t);
    }
};



//{ Driver Code Starts.

int main() {

    int T;
    cin >> T;
    cin.ignore();
    while (T--) {
        string s1;
        getline(cin, s1);
        string s2;
        getline(cin, s2);
        Solution ob;
        int ans = ob.editDistance(s1, s2);
        cout << ans << "\n";
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends