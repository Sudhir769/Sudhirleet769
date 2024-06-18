//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int rectanglesInCircle(int r) {
        int area = 3.14*(r*r);
        int cnt = 0;
        int max = 2 * r - 1;
        
        for(int i=1; i<= max; i++){
            for(int j=1; j<=max; j++){
                if(i*j <= area and pow(2*r, 2) >= pow(i, 2) + pow(j, 2)){
                    cnt++;
                }
            }
        }
        return cnt;
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
        int ans = ob.rectanglesInCircle(n);
        cout << ans << "\n";
    }
}
// } Driver Code Ends