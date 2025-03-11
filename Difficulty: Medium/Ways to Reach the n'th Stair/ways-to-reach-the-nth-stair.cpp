//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int countWays(int n) {
        if(n == 2 or n == 1){
            return n;
        }
        
        int w1 = 1;
        int w2 = 2;
        for(int i=3; i<=n; i++){
            int w3 = w2 + w1;
            w1 = w2;
            w2 = w3;
        }
        return w2;
    }
};



//{ Driver Code Starts.
int main() {
    // taking total testcases
    int t;
    cin >> t;
    while (t--) {
        // taking stair count
        int m;
        cin >> m;
        Solution ob;
        cout << ob.countWays(m) << endl; // Print the output from our pre computed array

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends