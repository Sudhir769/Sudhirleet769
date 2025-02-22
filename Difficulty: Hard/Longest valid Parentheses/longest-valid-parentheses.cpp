//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int maxLength(string& s) {
        int n = s.length();
        
        stack<int> st;
        st.push(-1);
        int maxi = 0;
        
        for(int i=0; i<n; i++){
            char ch = s[i];
            
            if(ch == '('){
                st.push(i);
            }else{
                st.pop();
                if(!st.empty()) maxi = max(maxi, i - st.top());
                else st.push(i);
            }
        }
        return maxi;
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
        cout << ob.maxLength(S) << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends