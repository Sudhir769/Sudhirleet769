//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:

    string pattern(vector<vector<int>> &arr) {
        int n = arr.size();
        string ans = "-1";
        for(int i=0; i<n; i++){
            bool flag = 1;
            for(int j=0, k=n-1; j<=k; j++, k--){
                if(arr[i][j] != arr[i][k]){
                    flag = 0;
                    break;
                }
            }
            if(flag){
                ans = to_string(i) + " " + "R";
                return ans;
            }
        }
        for(int i=0; i<n; i++){
            bool flag = 1;
            for(int j=0, k=n-1; j<=k; j++, k--){
                if(arr[j][i] != arr[k][i]){
                    flag = 0;
                    break;
                }
            }
            if(flag){
                ans = to_string(i) + " " + "C";
                return ans;
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {

    int t, n, i, j, flag, k;
    cin >> t;

    while (t--) {
        cin >> n;
        vector<vector<int>> a(n, vector<int>(n));

        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++)
                cin >> a[i][j];
        }
        Solution ob;
        cout << ob.pattern(a) << endl;
    }
    return 0;
}
// } Driver Code Ends