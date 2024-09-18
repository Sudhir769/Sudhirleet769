//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> findTwoElement(vector<int>& arr) {
        int n = arr.size();
        
        for(int i=0; i<n; i++) arr[i]--;
        for(int i=0; i<n; i++) arr[arr[i] % n] += n;
        
        int miss = -1, rep = -1;
        
        for(int i=0; i<n; i++){
            if(arr[i] / n == 2) rep = i+1;
            if(arr[i] / n == 0) miss = i+1;
        }
        return {rep, miss};
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}
// } Driver Code Ends