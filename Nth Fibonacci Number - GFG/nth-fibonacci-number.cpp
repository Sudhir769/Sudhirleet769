//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
  int mod=1e9+7;
    int nthFibonacci(int n){
        int t[n];
        t[0]=0;
        t[1]=1;
        
        for(int i=2;i<=n;i++){
            t[i]=(t[i-1]+t[i-2])%mod;
        }
        return t[n];
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
        cout << ob.nthFibonacci(n) << endl;
    }
    return 0;
}

// } Driver Code Ends