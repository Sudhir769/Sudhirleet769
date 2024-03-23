//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution {
  public:
    void printDiamond(int n) {
        for(int i=1; i<=n; i++) {
            cout << string(n-i, ' ');
            for(int j=0; j<i; j++)
                cout << "* ";
            cout << "\n";
        }
        for(int i=n; i>0; i--) {
            cout << string(n-i, ' ');
            for(int j=0; j<i; j++)
                cout << "* ";
            cout << "\n";
        }
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        Solution ob;
        ob.printDiamond(n);
    }
    return 0;
}
// } Driver Code Ends