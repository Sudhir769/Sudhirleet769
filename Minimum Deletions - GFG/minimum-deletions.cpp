//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int longestPalinSubseq(string s){
        string s1 = s;
        reverse(s.begin(), s.end());
        string s2 = s;
        
        int n = s.length();
        int dp[n+1][n+1];
        
        for(int i=0;i<=n;i++){
            for(int j =0; j<=n;j++){
                if(i==0 or j==0) dp[i][j]=0;
                else if(s1[i-1] == s2[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
                else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        return dp[n][n];
    }
    int minimumNumberOfDeletions(string s) { 
        int len = longestPalinSubseq(s);
        return s.size()-len;
    } 
};

//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--){
        string S;
        cin >> S;
        Solution obj;
        cout << obj.minimumNumberOfDeletions(S) << endl;
    }
    return 0;
}
// } Driver Code Ends