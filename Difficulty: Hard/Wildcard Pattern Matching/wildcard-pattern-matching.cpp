//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    /*You are required to complete this method*/
    vector<vector<int>>dp;
    bool solve(int i, int j, string s1, string s2){
        if(i<0 and j<0) return true;
        if(i < 0) return false;
        if(j < 0 ){
            for(int ii=0; ii<=i; ii++){
                if(s1[ii] != '*'){
                    return false;
                }
            }
            return true;
        }
        if(dp[i][j] != -1) return dp[i][j];
        
        if((s1[i] == s2[j]) or (s1[i] == '?')){
            return dp[i][j] = solve(i-1, j-1, s1, s2);
        }
        if(s1[i] == '*'){
            return dp[i][j] = solve(i-1, j, s1, s2) or solve(i, j-1, s1, s2);
        }
        return dp[i][j] = false;
    }
    int wildCard(string pattern, string str) {
        int n = pattern.length();
        int m = str.length();
        
        dp.resize(n+1, vector<int>(m+1, -1));
        return solve(n-1, m-1, pattern, str);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string pat, text;
        cin >> pat;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin >> text;
        Solution obj;
        cout << obj.wildCard(pat, text) << endl;
    }
}

// } Driver Code Ends