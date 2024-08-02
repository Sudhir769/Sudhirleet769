//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int dp[101][101];
    int solve(int i, int j, string &s1, string &s2){
        
        if(i < 0) return j+1;
        if(j < 0) return i+1;
        
        if(dp[i][j] != -1) return dp[i][j];
        
        if(s1[i] == s2[j]){
            return dp[i][j] = 0 + solve(i-1, j-1, s1, s2);
        }
        
        return dp[i][j] = 1 + min({solve(i-1, j, s1, s2), solve(i, j-1, s1, s2), solve(i-1, j-1, s1, s2)});
    }
    
    int editDistance(string str1, string str2) {
        
        memset(dp, -1, sizeof(dp));
        return solve(str1.length()-1, str2.length()-1, str1, str2);    
    }
};

//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;
    while (T--) {
        string s, t;
        cin >> s >> t;
        Solution ob;
        int ans = ob.editDistance(s, t);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends