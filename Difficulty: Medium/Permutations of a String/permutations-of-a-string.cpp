//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    unordered_set<string> st;
    void solve(int i, int n, string temp, string &s){
        if(i >= n){
            st.insert(temp);
            return;
        }
        
        for(int j=i; j<n; j++){
            swap(s[i], s[j]);
            temp = s;
            solve(i+1, n, temp, s);
            swap(s[i], s[j]);
        }
        
    }
    
    vector<string> findPermutation(string &s) {
        int n = s.length();
        solve(0, n, "", s);
        vector<string> ans(st.begin(), st.end());
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;
        Solution ob;
        vector<string> ans = ob.findPermutation(S);
        sort(ans.begin(), ans.end());
        for (auto i : ans) {
            cout << i << " ";
        }
        cout << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends